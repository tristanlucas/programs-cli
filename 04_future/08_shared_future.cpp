#include <iostream>
#include <future>
#include <thread>
#include <chrono>

using namespace std;


int factorial (std::shared_future<int> f){
    int res = 1;
    int N = f.get();
    for (int i = N; i > 1 ; i--){
        res *= i;
    }
    cout << "Result is = " << res << endl;
    return res;
}



int main(){
   
    std::promise<int> p ;

    //std::promise<int> p2 = std::move(p); // only moveable , not copyable objects.

    std::future<int> f = p.get_future();

    std::shared_future<int> sf = f.share();
    std::future<int> fu = std::async(std::launch::async, factorial, sf);
    std::future<int> fu1 = std::async(std::launch::async, factorial, sf);
    std::future<int> fu2 = std::async(std::launch::async, factorial, sf);
    std::future<int> fu3 = std::async(std::launch::async, factorial, sf);
    
    //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    // cannot pass the same future for all threads. 
    //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    p.set_value(4);
    //p.set_exception(std::make_exception_ptr(std::runtime_error("You broke the promises shit man!")));
    
    int x = fu.get();
    std::cout << "Getting result from child thread 1 = " << x << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    int x1 = fu1.get();
    std::cout << "Getting result from child thread 2 = " << x1 << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    int x2 = fu2.get();
    std::cout << "Getting result from child thread 3 = " << x2 << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    int x3 = fu3.get();
    std::cout << "Getting result from child thread 4 = " << x3 << std::endl;
    return 0;

}