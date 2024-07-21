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

int addSomeValue (std::shared_future<int> f){
    return f.get()+ 1; 
}


int main(){
   
    std::promise<int> p ;
    std::future<int> f = p.get_future();
    std::shared_future<int> sf = f.share();
    std::future<int> fu1 = std::async(std::launch::async, factorial, sf);
    std::future<int> fu3 = std::async(std::launch::async, factorial, sf);
    std::future<int> fu2 = std::async(std::launch::async, addSomeValue, sf);
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    // int a = 1;
    // if( a == 1){
    //     p.set_value(4);
    // }else {
    //     p.set_exception(std::make_exception_ptr(std::runtime_error("You broke the promises shit man!")));
    // }
    p.set_value(5);
    //p.set_exception(std::make_exception_ptr(std::runtime_error("You broke the promises shit man!")));
    int x = fu1.get();
    int y = fu2.get();
    int z = fu3.get();
    std::cout<<" Getting result from child thread = " << x << std::endl;
    std::cout << " Getting From Future Object No.2 = " << y << std::endl;
    std::cout << " Getting From Future Object No.3 = " << z << std::endl;
     return 0;

}