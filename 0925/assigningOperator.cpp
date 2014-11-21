/*************************************************************************
	> File Name: assigningOperator.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Sat 15 Nov 2014 06:34:01 AM PST
 ************************************************************************/
#include <iostream>
#include <string.h>

using namespace std;

class String
{
public:
    String();
    String(const char *s);
    String(const String &s);
    ~String();
    String &operator=(const String &s);

    size_t size() const
    {
        return strlen(str_);
    }

    void print() const
    {
        cout << str_ << endl;
    }

private:
    char *str_;
};

String::String()
        :str_(new char[1])
{ 
    *str_ = 0;
}

String::String(const char *s)
        :str_(new char[strlen(s) + 1])
{
    ::strcpy(str_, s);
}

String::String(const String &s)
        :str_(new char[strlen(s.str_) + 1])
{
    ::strcpy(str_, s.str_);
}


String::~String()
{
    delete[] str_; 
    cout << "destructor execute" << endl;
}


String &String::operator=(const String &s)
{
    if(this == &s) 
        return *this;

    delete[] str_;
    str_ = new char[s.size() + 1];
    ::strcpy(str_, s.str_);

    return *this;
}


int main(int argc, const char *argv[])
{
    String s("hello");   
    s.print();

    String s2;
    s2 = s;
    s2.print(); //hello

    s2 = s2;
    s2.print();
}
