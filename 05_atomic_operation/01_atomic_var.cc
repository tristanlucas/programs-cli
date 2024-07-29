#include <iostream>
#include <thread>
#include <atomic>

int main(){
    std::atomic<int> y(0);
    
    int x = y.load(); // Equivalent to T x = y
    int z = 9;
    y.store(z); // Equivalent to y = z
    std::cout<< " integer x = " << x << std::endl;
    std::cout<< " atomic y = " << y.load() << std::endl;

    int a = 3;
    int b = a;
    
}

