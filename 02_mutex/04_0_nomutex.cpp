#include <iostream>
#include <thread>


int myAmount=0;  // resource , critical area , shared resource , မင်းကြိုက်သလိုခေါ်
void addMoney()
{
    for(int i=0 ; i< 100000; i++){
    ++myAmount;
    }
}

int main(void)
{
    std::thread t1(addMoney);
    std::thread t2(addMoney);

    t1.join();
    t2.join();

    std::cout << myAmount << std::endl;
    return 0;

}