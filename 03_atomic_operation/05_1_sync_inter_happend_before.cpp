// happen_before
//inter-thread happen before
// synchronized with

#include<iostream>
#include<vector>
#include<atomic>
#include<chrono>
#include<thread>

std::atomic<bool> data_ready = false;
std::vector<int> data_vector ;

void reader_fun(){
    while (!data_ready)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    std::cout << data_vector[0] << std::endl;
}

void writer_fun(){
    data_vector.push_back(3);
    data_ready.store(true);
}

int main(){

    std::thread reader_th(reader_fun);
    std::thread writer_th(writer_fun);

    reader_th.join();
    writer_th.join();

}