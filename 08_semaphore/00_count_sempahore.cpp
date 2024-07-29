#include <iostream>
#include <thread>
#include <semaphore>
#include <vector>

std::counting_semaphore<3> sem(3);

void worker(int id) {
    sem.acquire();
    std::cout << "Worker " << id << " is running." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    sem.release();
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(worker, i);
    }
    for (auto& t : threads) {
        t.join();
    }
    return 0;
}

// 10 >> 
// Key 3 >> 
// 3 Threads >> acquire >> 3 Keys >> 0 Keys
// 7 Threads >> cannot acquire >> Wait >>
// 3 Threads Release >> 3 Keys
// 3 Threads >>   