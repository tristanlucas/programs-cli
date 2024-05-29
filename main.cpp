#include <iostream>

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
        std::cout << "size of arr is " << sizeof(arr[5]) ;
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


int main(){

    int x = 11;
    int y = 15;

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


    for(int i = 0; i <= 4 ; i++){
        //arr [i] = 23+i;
        //cout << "program is starting " << arr [i] << " please wait .. " << endl;
    }

    cout<< "enter [ 1 >> pointer pass, 2 >> name & Age, 3 >> X Y Z Corrdinates " << endl << " 4 >> job, 5 >> MemAddress, 6 >> array, 7 >> favMeal] ?" << endl ;
    int inputcase;
    cin >> inputcase;
    
    switch(inputcase){
        case 1:
            cout<< "Requesting For ap bp .. ";
            passByPtr(&personpoint->age, &personpoint->weight);
            cout<< "requesing for name .. ";
            personpoint->getName(personpoint->name);

        break;
        case 2:
            cout<< "Requesting For Name & Age .. ";
            personpoint->iam(age, personpoint->name);
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
        break;
        default:
            cout<< "Nothing to choose .. ";
        break;
    }

    //Entry Controlled Loop >> For , While
    //Exit Controlled Loop >> do while 
}
