#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

std::atomic<bool> done(false);

void thread_function(int id) {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread " << id << " iteration " << i + 1 << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        // Yield execution to allow the other thread to run
        //std::this_thread::yield();
    }
    done = true;
}

int main() {
    std::thread t1(thread_function, 1);
    std::thread t2(thread_function, 2);

    t1.join();
    t2.join();

    return 0;
}
