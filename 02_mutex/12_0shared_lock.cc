#include <iostream>
#include <thread>
#include <shared_mutex>
#include <chrono>

std::shared_mutex sharedMtx;
int sharedResource = 0;

void reader() {
    // Acquire a shared lock for reading
    std::shared_lock<std::shared_mutex> lock(sharedMtx);
    std::cout << "Reader reads sharedResource: " << sharedResource << std::endl;
    //std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate reading work
}

void writer() {
    // Acquire an exclusive lock for writing
    std::unique_lock<std::shared_mutex> lock(sharedMtx);
    ++sharedResource;
    std::cout << "Writer increments sharedResource to: " << sharedResource << std::endl;
    //std::this_thread::sleep_for(std::chrono::milliseconds(150)); // Simulate writing work
}

int main() {
    // Create one reader thread and one writer thread
    std::thread readerThread(reader);
    std::thread writerThread(writer);
    std::thread writerThread1(writer);
    std::thread readerThread1(reader);
    std::thread writerThread2(writer);
    std::thread readerThread2(reader);

    // Join the threads
    readerThread.join();
    writerThread.join();
    readerThread1.join();
    writerThread1.join();
    writerThread2.join();
    readerThread2.join();
    

    std::cout << "Final value of sharedResource: " << sharedResource << std::endl;

    return 0;
}
