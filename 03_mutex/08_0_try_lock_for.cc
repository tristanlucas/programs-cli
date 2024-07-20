#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::timed_mutex mtx;

void attemptLockWithRelativeTime(int id) {
    if (mtx.try_lock_for(std::chrono::seconds(2))) {
        std::cout << "Thread " << id << " acquired the lock." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate work
        mtx.unlock();
    } else {
        std::cout << "Thread " << id << " could not acquire the lock." << std::endl;
    }
}

int main() {
    std::thread t1(attemptLockWithRelativeTime, 1);
    std::thread t2(attemptLockWithRelativeTime, 2);

    t1.join();
    t2.join();

    return 0;
}

//t1 tries to acquire the lock for up to 2 seconds.
//If it succeeds, it locks the mutex, does some work, and then unlocks it.
//t2 also tries to acquire the lock for up to 2 seconds. 
//Depending on the timing, it may or may not succeed.