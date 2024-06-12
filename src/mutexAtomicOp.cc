// 8_raceCondition_03.cpp
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <atomic>

// (1) Race Condition 01: The race condition may not happen if the CPU is faster enough
int sharedVariable_race_01 = 0;

void increment_race_01() {
    for (int i = 0; i < 100000; ++i) {
        std::this_thread::sleep_for(std::chrono::microseconds(1));
        sharedVariable_race_01++;
    }
}

// (2) Race Condition 02: Introduce delay to make race condition happen definitely
int sharedVariable_race_02 = 0;
//int currentValue_02 = sharedVariable_race_02;

void increment_race_02() {
    for (int i = 0; i < 100000; ++i) {
        //int currentValue_02 = sharedVariable_race_02;
        std::this_thread::sleep_for(std::chrono::microseconds(1)); // Introduce a delay
        sharedVariable_race_02 ++;
    }
}

int sharedVariable_mutex = 0;
std::mutex mtx;

void increment_mutex() {
    for (int i = 0; i < 100000; ++i) {
        std::lock_guard<std::mutex> lock(mtx); // Automatically locks and unlocks
        sharedVariable_mutex++;
    }
}
/*
std::lock_guard is a safer alternative to manual locking and unlocking because it
automatically unlocks the mutex when it goes out of scope.
*/

std::atomic<int> sharedVariable_atomic(0);

void increment_atomic() {
    for (int i = 0; i < 100000; ++i) {
        sharedVariable_atomic++;
    }
}
/*
In this example, sharedVariable is declared as std::atomic<int>.
Atomic operations are indivisible, ensuring that the variable is incremented
correctly even when multiple threads access it concurrently.
*/


int main() {
    std::thread thread1(increment_race_01);
    std::thread thread2(increment_race_01);
    std::thread thread3(increment_race_02);
    std::thread thread4(increment_race_02);
    std::thread thread9(increment_race_02);

    std::thread thread5(increment_mutex);
    std::thread thread6(increment_mutex);
    std::thread thread7(increment_atomic);
    std::thread thread8(increment_atomic);

    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
    thread9.join();
    thread5.join();
    thread6.join();
    thread7.join();
    thread8.join();

    std::cout << "Expected value: 200000" << std::endl;

    std::cout << "Actual value of Race Condition: 01 " << sharedVariable_race_01 << std::endl;
    std::cout << "Actual value of Race Condition: 02 " << sharedVariable_race_02 << std::endl;

    std::cout << "Actual value of Mutex: " << sharedVariable_mutex << std::endl;
    std::cout << "Actual value of Atomic: " << sharedVariable_atomic.load() << std::endl;

    return 0;
}