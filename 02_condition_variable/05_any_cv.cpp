#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <condition_variable>
#include <vector>

std::shared_mutex mtx;
std::condition_variable_any cv;
bool ready = false;

void readerThread(int id) {
    std::shared_lock<std::shared_mutex> lock(mtx);
    cv.wait(lock, []{ return ready; });
    std::cout << "Reader thread " << id << " is processing data." << std::endl;
}

void writerThread() {
    std::unique_lock<std::shared_mutex> lock(mtx);
    ready = true;
    cv.notify_all();
    std::cout << "Writer thread has set the condition and notified all." << std::endl;
}

int main() {
    const int num_readers = 5;
    std::vector<std::thread> threads;
    for (int i = 0; i < num_readers; ++i) {
        threads.emplace_back(readerThread, i);
    }

    std::thread writer(writerThread);

    for (auto& t : threads) {
        t.join();
    }
    writer.join();

    std::cout << "All threads finished processing. Back in main." << std::endl;

    return 0;
}
