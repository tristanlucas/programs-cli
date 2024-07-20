#include <iostream>
#include <thread>
#include <queue>
#include <vector>
#include <chrono>

std::queue<int> queue;

void producer(int id) {
    for (int i = 0; i < 10; ++i) {
        int item = rand() % 100;
        queue.push(item);  // Data race: multiple producers can write concurrently
        std::cout << "Producer " << id << " produced " << item << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void consumer(int id) {
    for (int i = 0; i < 10; ++i) {
        if (!queue.empty()) {
            int item = queue.front();  // Data race: consumers can read/write concurrently
            queue.pop();
            std::cout << "Consumer " << id << " consumed " << item << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}

int main() {
    std::thread producer1(producer, 1);
    std::thread producer2(producer, 2);
    std::thread consumer1(consumer, 1);
    std::thread consumer2(consumer, 2);

    producer1.join();
    producer2.join();
    consumer1.join();
    consumer2.join();

    return 0;
}
