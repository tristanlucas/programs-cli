#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

class home{
    private:
    int arr [5] ;
    //int inf_arr [] = {233,226,54,21,289,304};
    int arrmatrix [3][4][4] ; // 3 dimension matrix

    public:
    int no ;
    string address ;

    void setArrValue(int index, int value){
        if(index>=0 && index<5){
            arr[index]=value;
        }else {
            cout << "Out of index" << endl;
        }
    }

    int getArrValue(int index){
        if(index>=0 && index<5){
            return arr[index];
        }else{
            cout << "Index out of bound"; 
            return -1;
        }
    }

    void printArr(){
        for (int i=0; i<5; i++){
            cout << "array no "<< i << " is " << arr[i] << std::endl; ;
        }
        std::cout << "size of arr in bytes is " << sizeof(arr) << " bytes" << endl ; // int = 4 bytes * 5 arr = 20 bytes. 
        std::cout << "size of arr is " << sizeof(arr[5]) << endl;
    }


    void whereisit(string address){
        cout << "Address is : " << address << endl;
    }
    void whatishomeNo(int no){
        cout << "Home No is : " << no << endl;
    }
    void display(int &a){
        cout << " reference value is : " << &a << endl;
    }
    void multiply (int *x, int *y){
        int mrst = (*x) * (*y);
    cout << " x * y = " <<  mrst << endl; 
    
    }
};

struct personal{
    int age ;
    string name ;
    float weight;
    int& a = age;

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

void whereisXYZ( int x, double y = 15, double z = 15.6){
    cout << "address of x is " << &x << endl;
    cout << "value of x is " << x << endl;
    cout << "address of y is " << &y << endl;
    cout << "value of y is " << y << endl;
    cout << "address of z is " << &z << endl;
    cout << "value of z is " << z << endl;
}

void passByPtr(int *ap, float * bp){
    cout << "point to ap .. " << *ap << endl;
    cout << "point to bp .. " << *bp << endl;
    cout << "address to bp .. " << bp << endl;
    cout << "address to ap .. " << ap << endl;
}

void findArr2Size(double (&arr2)[10]){
    cout << "Size of double array 2 is : " << sizeof(arr2) << endl;
}

void ptr_arr(){
    int marks[10];
    int *ptr=marks;
    cout << "address of marks is : " << &marks << endl;
    //cout << "pointer of marks is : " << ++ptr << endl; // added 4 bytes
    int *ptr1 = ptr ;
    cout << "pointer plus of ptr1 is : " << &ptr1 << endl; //address of ptr1 pointer
    cout << "plus pointer of ++ptr is : " << ++ptr << endl; // added 4 bytes
}

void stringRepresent(){
    char st[] = {"Hello GEO"};
    std::cout << st << endl; 
    std::cout << "the size of st is " << sizeof(st) << std::endl; 

}

int main(){

    int x = 11;
    int y = 15;
    
    double arr2[10];

    personal *personpoint = &personptr;
    personpoint->name = "KyawSwar Tun";
    personpoint->age = 15;
    cout << "address of personpoint->age is " << &personpoint->age << endl;
    personpoint->weight = 30.01;
    cout << "address of personpoint->weight is " << &personpoint->weight << endl;
    
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


    std::map<char, int> mydist{{'a',27}, {'b',22}};

    for(const auto& [key, value]: mydist){
        
        cout <<  key << " has the value " << value << endl;
    }

    int num = 12;
    int& ref = num;
    const int& refx = ref;
    cout << "Reference is " << &ref << " "<< refx <<  endl;
    //int& refx = 11;


    cout << "aa 1 >> pointer pass" << 
    endl << "bb 1 >> name & Age" <<
    endl << "cc 1 >> X Y Z Corrdinates " <<  
    endl << "dd 1 >> job"<< 
    endl << "ee 1 >> MemAddress" <<
    endl << "ff 1 >> array" << 
    endl << "gg 1 >> arrPtr " << 
    endl << "hh 1 >> typeCasting " << 
    endl << "ii 1 >> Reserved " << 
    endl << "exit() to quit! " << 
    endl << " >> "; 
    std::unordered_map<std::string, int> cases;
    cases["aa 1"] = 1;
    cases["bb 1"] = 2;
    cases["cc 1"] = 3;
    cases["dd 1"] = 4;
    cases["ee 1"] = 5;
    cases["ff 1"] = 6;
    cases["gg 1"] = 7;
    cases["hh 1"] = 8;
    cases["ii 1"] = 9;

while(true){
    string inputcase;
    //cin >> inputcase;
    getline(cin, inputcase);
    if (inputcase == "exit()") {
            break;
        }

    switch(cases[inputcase]){
        case 1:
            cout<< "Requesting For ap bp .. ";
            passByPtr(&personpoint->age, &personpoint->weight);
            cout<< "requesing for name .. ";
            personpoint->getName(personpoint->name);

        break;
        case 2:
            cout<< "Requesting For Name & Age .. ";
            personpoint->iam(age, personpoint->name);
            cout<< "Age of a is : " << &personpoint->age << endl;
            cout<< "Age of a is : " << a << endl;
        break;
        case 3:
            cout<< "Requesting X Y Z Corrdinates ..";
            whereisXYZ(x);
            h1.multiply(&x, &y);
        break;
        case 4:
            cout << " Requesting For Address .. ";
            h1.whereisit(h1.address);
        break;
        case 5:
            cout << "Requesting Memory Address .. ";
            h1.display(*a);
        case 6:
            //cout << "Printing Value of Array .. ";
            h1.setArrValue(0,123);
            h1.setArrValue(1,223);
            h1.setArrValue(2,222);
            h1.setArrValue(3,540);
            h1.setArrValue(4,520);
            cout << "The value is " << h1.getArrValue(2) << endl;
            h1.printArr();
            findArr2Size(arr2);
        break;
        case 7:
            cout<< "------ Printing Ptr & Array ! --------" << endl;
            ptr_arr();
        break;
        case 8:
            cout<< "------ String Representation ! --------" << endl;
            stringRepresent();
        break;
        default:
            cout<< "Shut the fuck up Bitch !" << "Type What I said !" << endl;
        break;
    }

}

    //Entry Controlled Loop >> For , While
    //Exit Controlled Loop >> do while 
}
