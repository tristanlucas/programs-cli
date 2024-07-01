#include <iostream>
#include <thread>
#include <atomic>

int main()
{
    std::atomic<int> sum(0);
   
    auto f = [&sum](){
        for(int i = 0; i < 1000000; i++)
        {
            sum ++;
        }
    };

    std::thread t1(f);
    std::thread t2(f);

    t1.join();
    t2.join();
   
    std::cout << sum << std::endl;

    return 0;
}