#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <chrono>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void workerThread(int id) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{ return ready; });
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "Worker thread " << id << " is processing data." << std::endl;
}

int main() {
    const int num_threads = 5;
    std::vector<std::thread> threads;
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(workerThread, i);
    }
    
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true; 
    }

    cv.notify_all(); 

    
    for (auto& t : threads) {
        t.join();
    }
    std::cout << "All worker threads finished processing. Back in main." << std::endl;

    return 0;
}
