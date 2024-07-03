//std::shared_lock is part of the C++17 standard library and is used 
//with std::shared_mutex to allow multiple readers but only one writer. 
//This is particularly useful when you have a resource that is frequently read 
//but only occasionally written to, as it allows for more efficient 
//concurrent access.

//Shared Lock: std::shared_lock is used to acquire a shared lock on a std::shared_mutex.

#include <iostream>
#include <thread>
#include <shared_mutex>
#include <vector>
#include <chrono>

std::shared_mutex sharedMtx;
int sharedResource = 0;

void reader(int threadID) {
    for (int i = 0; i < 5; ++i) {
        std::shared_lock<std::shared_mutex> lock(sharedMtx);
        std::cout << "Reader " << threadID << " reads sharedResource: " << sharedResource << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate reading work
    }
}

void writer(int threadID) {
    for (int i = 0; i < 5; ++i) {
        std::unique_lock<std::shared_mutex> lock(sharedMtx);
        ++sharedResource;
        std::cout << "Writer " << threadID << " increments sharedResource to: " << sharedResource << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(150)); // Simulate writing work
    }
}

int main() {
    std::vector<std::thread> threads;

    // Create multiple reader threads
    for (int i = 0; i < 3; ++i) {
        threads.emplace_back(reader, i);
    }

    // Create multiple writer threads
    for (int i = 0; i < 2; ++i) {
        threads.emplace_back(writer, i);
    }

    // Join all threads
    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Final value of sharedResource: " << sharedResource << std::endl;

    return 0;
}
