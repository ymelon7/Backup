/*************************************************************************
	> File Name: inherit.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Fri 21 Nov 2014 06:21:39 AM PST
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    Person()
        :id_(0), name_(""), age_(0)
    {  }
    Person(int id, const string &name, int age)
        :id_(id), name_(name), age_(age)
    {  }


    void print() const
    {
        cout << "id = " << id_ << " name = " << name_
            << " age = " << age_ << endl;
    }

private:
    int id_;
    string name_;
    int age_;
};


class Student : public Person
{
public:
    Student() :school_("")  {  }
    Student(int id, const string &name, int age, const string &school)
        :Person(id, name, age), school_(school)
    {  }
    Student(const Student &s)
        :Person(s), school_(s.school_)
    {
    
    }
    Student &operator=(const Student &s)
    {
        if(this != &s)
        {
            Person::operator=(s);
            school_ = s.school_; 
        }

        return *this;
    }
    void test()
    {
        cout << "test" << endl; 
    }
    void print() const
    {
        Person::print();
        cout << "school = " << school_ << endl; 
    }

private:
    string school_;
};


int main (int argc, char *argv[])
{
    Student s(32, "RT", 12, "Stanford");
    s.print();

    Student s2(s);
    s2.print();

    Student s3;
    s3 = s;
    s3.print();

}
