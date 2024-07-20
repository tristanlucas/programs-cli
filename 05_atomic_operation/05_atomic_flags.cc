#include <iostream>
#include <atomic>
#include <thread>

std::atomic_flag flag = ATOMIC_FLAG_INIT;

void thread_function(int thread_id) {
    while (flag.test_and_set(std::memory_order_acquire)) {
        std::cout << "Thread " << thread_id << " is waiting...\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }

    std::cout << "Thread " << thread_id << " is working...\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));

    flag.clear(std::memory_order_release);
}

int main() {
    std::thread t1(thread_function, 1);
    std::thread t2(thread_function, 2);

    t1.join();
    t2.join();

    return 0;
}
