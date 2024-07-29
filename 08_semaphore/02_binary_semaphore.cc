#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

class BinarySemaphore {
public:
    BinarySemaphore() : flag(false) {}

    void acquire() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]() { return !flag; });
        flag = true;
    }

    void release() {
        std::unique_lock<std::mutex> lock(mtx);
        flag = false;
        cv.notify_one();
    }

private:
    std::mutex mtx;
    std::condition_variable cv;
    bool flag;
};

void worker(int id, BinarySemaphore& semaphore) {
    semaphore.acquire();
    std::cout << "Thread " << id << " is working." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate work
    std::cout << "Thread " << id << " is done." << std::endl;
    semaphore.release();
}

int main() {
    BinarySemaphore semaphore;

    std::thread t1(worker, 1, std::ref(semaphore));
    std::thread t2(worker, 2, std::ref(semaphore));

    t1.join();
    t2.join();

    return 0;
}
