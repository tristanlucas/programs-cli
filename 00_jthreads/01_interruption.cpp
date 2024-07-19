#include <iostream>
#include <thread>
#include <chrono>
#include <coroutine>
#include <future>

struct Task {
    struct promise_type {
        Task get_return_object() {
            return Task{std::coroutine_handle<promise_type>::from_promise(*this)};
        }
        std::suspend_never initial_suspend() {
            return {};
        }
        std::suspend_never final_suspend() noexcept {
            return {};
        }
        void return_void() {}
        void unhandled_exception() {
            std::terminate();
        }
    };

    std::coroutine_handle<promise_type> handle;

    Task(std::coroutine_handle<promise_type> handle) : handle(handle) {}

    ~Task() {
        if (handle) handle.destroy();
    }

    void start() {
        if (handle) handle.resume();
    }
};

Task exampleCoroutine(std::promise<void>& promise) {
    std::cout << "Coroutine: started" << std::endl;
    co_await std::suspend_always{};
    std::cout << "Coroutine: resumed" << std::endl;
    promise.set_value();
}

void threadFunction(std::future<void>& future) {
    std::cout << "Thread: waiting for coroutine" << std::endl;
    future.get(); // Wait for the coroutine to signal
    std::cout << "Thread: coroutine finished" << std::endl;
}

int main() {
    std::promise<void> promise;
    std::future<void> future = promise.get_future();

    // Start the coroutine
    auto coroutine = exampleCoroutine(promise);
    coroutine.start();

    // Start the thread
    std::thread t(threadFunction, std::ref(future));

    // Wait for the thread to finish
    t.join();

    return 0;
}
