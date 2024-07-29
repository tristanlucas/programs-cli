#include <iostream>
#include <string>

class Student
{
	public:
        Student() = default;
		Student(std::string name) : name_(name) {};
		//this function *might* change the object
		const std::string name() { return name_; }; // where is const?
        void Print(){
    std::cout << this ;
}

	private:
		std::string name_;
};



void Print( Student& stu)
{
	std::cout << "Student: " << stu.name() << std::endl;
}

int main()
{
    Student test;
    std::cout<< &test;
	Student s1{"mg mg"};
	test.Print();
    Print(s1);
    Student s2{"aye aye"};
    Print(s2);
	return 0;
}

