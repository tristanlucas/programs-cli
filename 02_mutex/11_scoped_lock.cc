#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>

std::mutex mtx1;
std::mutex mtx2;
int resource1 = 0;
int resource2 = 0;

void updateResources(int threadID) {
    for (int i = 0; i < 5; ++i) {
        {
            std::scoped_lock lock(mtx1, mtx2); // Lock both mutexes
            ++resource1;
            ++resource2;
            std::cout << "Thread " << threadID << " updated resources to: "
                      << "resource1 = " << resource1
                      << ", resource2 = " << resource2 << std::endl;
        } // Mutexes are automatically released here

        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
    }
}

int main() {
    std::vector<std::thread> threads;

    // Create multiple threads
    for (int i = 0; i < 3; ++i) {
        threads.emplace_back(updateResources, i);
    }

    // Join threads to ensure completion before exiting main
    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Final resource values: "
              << "resource1 = " << resource1
              << ", resource2 = " << resource2 << std::endl;

    return 0;
}
