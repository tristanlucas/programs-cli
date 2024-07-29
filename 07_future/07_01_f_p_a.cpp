#include <iostream>
#include <future>
#include <thread>
#include <chrono>
using namespace std;


int factorial (std::future<int>& f){
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
    std::future<int> f = p.get_future();
    // std::thread t1 (factorial, 4, std::ref(x));
    // t1.join();
    std::future<int> fu = std::async(std::launch::async, factorial, std::ref(f));

    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    p.set_value(4);

    int x = fu.get();
    std::cout<<" Getting result from child thread = " << x << std::endl;
    return 0;

}