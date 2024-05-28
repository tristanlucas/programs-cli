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
    void display(int &a){
    cout << " reference value is : " << &a << endl;

}

};

struct personal{
    int age ;
    string name ;
    float weight;

    void iam(int age, string name){
        cout << "I am " << name << " and " << age << "years old now" << endl;
    }
    void getName(string name){
        cout << "I am " << name << endl;
    }
    void getName(float weight){
        cout << "I am " << weight << endl;
    }
}personptr;


int main(){

    personal *personpoint = &personptr;
    personpoint->name = "KyawSwar Tun";
    personpoint->age = 15;
    personpoint->weight = 30.01;
    

    home h1;
    h1.address = "South Okkaplapa";
    h1.no=223;
    int *a = &h1.no;
    h1.whereisit(h1.address);
    h1.whatishomeNo(h1.no);

    
    
    enum questions{
        name,
        age,
        address,
        job,
        pet,
        passion,
        favMeal,

    };

    for(int i = 5; i <= 5 ; i++){
        cout << "program is starting " << i++ << "please wait .. " << endl;
    }

    cout<< "enter [ 1 >> name, 2 >> name & Age, 3 >> Age Only " << endl << " 4 >> job, 5 >> MemAddress, 6 >> passion, 7 >> favMeal] ?" << endl;
    int inputcase;
    cin >> inputcase;
    
    switch(inputcase){
        case 1:
            cout<< "Requesting For Name .. ";
            personpoint->getName(personpoint->name);
        break;
        case 2:
            cout<< "Requesting For Name & Age .. ";
            personpoint->iam(age, personpoint->name);
        break;
        case 3:
            cout<< "Requesting For Age ..";
            personpoint->age = age;
        break;
        case 4:
            cout << " Requesting For Address .. ";
            h1.whereisit(h1.address);
        break;
        case 5:
            cout << "Requesting Memory Address .. ";
            h1.display(*a);
        default:
            cout<< "Nothing to choose .. ";
        break;
    }

    //Entry Controlled Loop >> For , While
    //Exit Controlled Loop >> do while 


}
