#include<iostream>
#include<atomic>


int main(){
    std::atomic<int> x(0);
    std::atomic<int> z(12);
    int y = 42;
    int x0 = x.exchange(y); // (x0 = x; x = y;) done atomically
    int x1 = z.exchange(y); // (x0 = x; x = y;) done atomically

    std::cout<< "value of y = " << y << std::endl;
    std::cout<< "value of x0 = " << x0 << std::endl;
    std::cout<< "value of x1 = " << x1 << std::endl;
    std::cout<< "atomic exchanged value of x = " << x.load() << std::endl;
    std::cout<< "atomic exchanged value of z = " << z.load() << std::endl;
}


