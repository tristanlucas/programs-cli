#include <iostream>
#include <future>
#include <thread>
#include <chrono>

// Function to be run asynchronously
int computeSum(int a, int b) {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate a time-consuming task
    return a + b;
}

int main() {
    // Start an asynchronous task
    std::future<int> futureResult = std::async(std::launch::async, computeSum, 5, 10);

    std::cout << "Computing the sum asynchronously...\n";

    // Wait for the result
    int result = futureResult.get();

    std::cout << "Result: " << result << std::endl;
    //std::cout << "Result: " << futureResult << std::endl;

    return 0;
}
