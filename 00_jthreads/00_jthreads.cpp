#include<thread>
#include<iostream>

using namespace::std::literals;
void doSomeWork(std::stop_token token){
    int counter{0};
    while (counter < 10)
    {
        if (token.stop_requested()){
            return;
        }
        std::this_thread::sleep_for(0.2s);
        std::cerr<< "This is interruptible thread : " << counter << std::endl;
        ++counter ;
    }
}

void doDoChaCha(){
    int counter{0};
    while (counter < 5)
    {
        std::this_thread::sleep_for(0.2s);
        std::cout<< "This is interruptible thread : " << counter << std::endl;
        ++counter ;
    }
}

int main(){

    std::cout<< std::endl;
    std::jthread jt1(doSomeWork);
    std::jthread jt2(doDoChaCha);
    // automatically destruction and 
    std::this_thread::sleep_for(1s);
    jt1.request_stop(); // interruption with stop token
    jt2.request_stop();
    std::cout<< std::endl;

}
