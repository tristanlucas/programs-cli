#include<iostream>
#include<thread>
#include<future>

using namespace std::

std::queue<std::packaged_task>int()> > task_q;
std::mutex mu;
std::condition_variable cond;

void thread_1(){
    std::packaged_task<int()> t;
    {
        std::lock_guard<std::mutex> locker(mu);
        t= std::move(task_q.front());
        task_q.pop_front();
    }
    t();
} 

int main(){
    std::thread t1(thread_1);
    std::packaged_task<int()> t(std::bind(factorial,6));
    std::future<int> fu= t.get_future();
    {
    std::lock_guard<std::mutex> locker(mu);
    task_q.push_back(std::move(t));
}
    cond.notify_one();
    cout<<fu.get();

    t1.join();
    return 0;
}