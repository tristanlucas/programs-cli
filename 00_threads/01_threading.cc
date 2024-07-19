#include <iostream>
#include <thread>
#include <chrono>
void function1(char a) {
    //char b = a;
    for (int i = 0; i < 200; ++i) {
        std::cout << a;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
void function2() {
    for (int i = 0; i < 200; ++i) {
        std::cout << "B";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
int main() {
    std::thread worker1(function1, 'H');
    std::thread worker2(function2);
    worker1.join();
    worker2.join();
    std::cout << "\n";
    std::cout << __cplusplus << std::endl;
}
