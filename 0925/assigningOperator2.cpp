/*************************************************************************
	> File Name: assigningOperator2.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Sat 15 Nov 2014 06:42:38 AM PST
 ************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Student
{
public:
    Student() {}

    Student(int id, const string &name, int age)
        :id_(id), name_(name), age_(age)
    {  }

    Student(const Student &other)
        :id_(other.id_),
        name_(other.name_),
        age_(other.age_)
    {  }

    Student &operator=(const Student &s)
    {
        id_ = s.id_;
        name_ = s.name_;
        age_ = s.age_;
    }


    void print() const
    {
        cout << id_ << " : " << name_ << " : " << age_ << endl;
    }

private:
    int id_;
    string name_;
    int age_;
};


int main(int argc, const char *argv[])
{
    Student s(11, "zhangsan", 23);

    s.print();

    Student s2;
    s2 = s;
    s2.print();
}
