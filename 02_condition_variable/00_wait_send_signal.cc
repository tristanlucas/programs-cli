#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void waitFunction() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{ return ready; });
    std::cout << "Thread is proceeding after signal." << std::endl;
}

void signalFunction() {
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate work
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
    }
    cv.notify_one();
    std::cout << "Signal sent to waiting thread." << std::endl;
}

int main() {
    std::thread waiter(waitFunction);
    std::thread signaler(signalFunction);

    waiter.join();
    signaler.join();

    return 0;
}
