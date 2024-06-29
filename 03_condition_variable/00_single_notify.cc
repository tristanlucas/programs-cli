#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void workerThread() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{ return ready; });

    // Perform work after the condition is met
    std::cout << "Worker thread is processing data." << std::endl;
}

int main() {
    std::thread worker(workerThread);

    {
        std::lock_guard<std::mutex> lock(mtx);
        std::this_thread::sleep_for(std::chrono::seconds(5));
        ready = true;
        
    }

    cv.notify_one();

    worker.join();
    std::cout << "Back in main." << std::endl;

    return 0;
}