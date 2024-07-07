#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

//decrement counting .. 

class CountingSemaphore {
public:
    explicit CountingSemaphore(int count) : count(count) {}

    void acquire() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]() { return count > 0; });
        --count;
    }

    void release() {
        std::unique_lock<std::mutex> lock(mtx);
        ++count;
        cv.notify_one();
    }

private:
    std::mutex mtx;
    std::condition_variable cv;
    int count;
};

void worker(int id, CountingSemaphore& semaphore) {
    semaphore.acquire();
    std::cout << "Thread " << id << " is aquired." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1)); 
    std::cout << "Thread " << id << " is released." << std::endl;
    semaphore.release();
}

int main() {
    const int maxConcurrentThreads = 5;
    CountingSemaphore semaphore(maxConcurrentThreads);

    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(worker, i, std::ref(semaphore));
    }

    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
