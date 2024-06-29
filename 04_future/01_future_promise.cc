#include <iostream>
#include <future>
#include <thread>
#include <chrono>

// Function to set the value of the promise
void computeProduct(std::promise<int>& prom, int a, int b) {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate a time-consuming task
    int result = a * b;
    prom.set_value(result);
}

int main() {
    // Create a promise object
    std::promise<int> prom;

    // Get a future from the promise
    std::future<int> futureResult = prom.get_future();

    // Start a thread and pass the promise to it
    std::thread t(computeProduct, std::ref(prom), 5, 10);

    std::cout << "Computing the product asynchronously...\n";

    // Wait for the result
    int result = futureResult.get();

    std::cout << "Result: " << result << std::endl;

    t.join();

    return 0;
}
