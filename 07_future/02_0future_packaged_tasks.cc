#include <iostream>
#include <future>
#include <thread>
#include <chrono>

int computeDifference(int a, int b) {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate a time-consuming task
    return a - b;
}

int main() {
    std::packaged_task<int(int, int)> task(computeDifference);
    std::future<int> futureResult = task.get_future();
    std::thread t(std::move(task), 10, 5);
    std::cout << "Computing the difference asynchronously...\n";

    int result = futureResult.get();
    std::cout << "Result: " << result << std::endl;
    t.join();
    return 0;
}
