#include <iostream>
#include <thread>
#include <chrono>
#include <coroutine>
#include <future>
#include <vector>

template<typename T>
struct Generator {
    struct promise_type {
        T current_value;

        Generator get_return_object() {
            return Generator{std::coroutine_handle<promise_type>::from_promise(*this)};
        }

        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        std::suspend_always yield_value(T value) {
            current_value = value;
            return {};
        }
        void return_void() {}
        void unhandled_exception() { std::terminate(); }
    };

    std::coroutine_handle<promise_type> handle;

    Generator(std::coroutine_handle<promise_type> handle) : handle(handle) {}
    ~Generator() {
        if (handle) handle.destroy();
    }

    bool move_next() {
        handle.resume();
        return !handle.done();
    }

    T current_value() {
        return handle.promise().current_value;
    }
};

struct Awaiter {
    std::chrono::milliseconds duration;

    Awaiter(std::chrono::milliseconds duration) : duration(duration) {}

    bool await_ready() {
        return false;
    }

    void await_suspend(std::coroutine_handle<> handle) {
        std::thread([handle, this] {
            std::this_thread::sleep_for(duration);
            handle.resume();
        }).detach();
    }

    void await_resume() {}
};

Awaiter custom_awaitable(std::chrono::milliseconds duration) {
    return Awaiter{duration};
}

Generator<int> exampleCoroutine() {
    std::cout << "Coroutine: started" << std::endl;
    co_await custom_awaitable(std::chrono::milliseconds(500));
    std::cout << "Coroutine: after first await" << std::endl;

    for (int i = 0; i < 5; ++i) {
        co_yield i;
    }

    std::cout << "Coroutine: before return" << std::endl;
    co_return;
}

int main() {
    auto generator = exampleCoroutine();

    while (generator.move_next()) {
        std::cout << "Coroutine yielded: " << generator.current_value() << std::endl;
    }

    std::cout << "Coroutine completed" << std::endl;

    return 0;
}
