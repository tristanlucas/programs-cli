#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <chrono>

std::queue<int> queue;
std::mutex queue_mutex;
std::condition_variable queue_cv;
const int max_queue_size = 1;

void producer(int id) {
    while (true) {
        std::unique_lock<std::mutex> lock(queue_mutex);
        
        queue_cv.wait(lock, [] { return queue.size() < max_queue_size; });

        int item = rand() % 100;
        queue.push(item);
        std::cout << "Producer " << id << " produced " << item << std::endl;

        // a deadlock scenario by holding the lock while waiting
        queue_cv.notify_all();

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void consumer(int id) {
    while (true) {
        std::unique_lock<std::mutex> lock(queue_mutex);

        queue_cv.wait(lock, [] { return !queue.empty(); });

        int item = queue.front();
        queue.pop();
        std::cout << "Consumer " << id << " consumed " << item << std::endl;

        // a deadlock scenario by holding the lock while waiting
        queue_cv.notify_all();

        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}

int main() {
    std::thread producer1(producer, 1);
    //std::thread producer2(producer, 2);
    std::thread consumer1(consumer, 1);
    //std::thread consumer2(consumer, 2);

    producer1.join();
    //producer2.join();
    consumer1.join();
    //consumer2.join();

    return 0;
}
