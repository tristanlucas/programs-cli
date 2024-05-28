#include <iostream>

using namespace std;

class home{
    public:
    int no ;
    string address ;
    void whereisit(string address){
        cout << "Address is : " << address << endl;
    }
    void whatishomeNo(int no){
        cout << "Home No is : " << no << endl;
    }

};

struct personal{
    int age = 19;
    string name = "KyawswarTun";
    void iam(int age, string name){

        cout << "I am " << name << " and " << age << "years old now" << endl;

    }
}personptr;

int main(){

    home h1;
    h1.address = "South Okkaplapa";
    h1.no=223;
    h1.whereisit(h1.address);
    h1.whatishomeNo(h1.no);

    personal *personpoint = &personptr;
    personpoint->age = 22;
    personpoint->name = "KyawswarHtun";
    personpoint->iam(personpoint->age, personpoint->name);

    
    enum questions{
        name,
        age,
        // address,
        // job,
        // pet,
        // passion,
        // favMeal,

    };

    questions q = name;
    switch(q){
        case name:
            cout<< "Requesting For Name .. ";
        break;
        case age:
            cout<< "Requesting For Age .. ";
        break;
    }

}
