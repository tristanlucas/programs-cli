#include <atomic>
#include <iostream>
#include <thread>

std::atomic<bool> ready(false);

void wait_for_ready() {
    while (!ready.load(std::memory_order_acquire)) {
        std::this_thread::yield(); // Wait until ready is set
    }
    std::cout << "Ready flag is set. Proceeding...\n";
}

void set_ready() {
    // Simulate some work
    std::this_thread::sleep_for(std::chrono::seconds(1));
    ready.store(true, std::memory_order_release); // Set ready flag
}

int main() {
    std::thread t1(wait_for_ready);
    std::thread t2(set_ready);

    t1.join();
    t2.join();

    return 0;
}