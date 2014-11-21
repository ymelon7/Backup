/*************************************************************************
	> File Name: shallowCopy.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Sat 15 Nov 2014 06:16:09 AM PST
 ************************************************************************/
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class String
{
public:
    String();
    String(const char *s);
    String(const String &s);
    ~String();

    void print() const
    {
        cout << str_ << endl;
    }

private:
    char *str_;
};

String::String()
        :str_(new char(0))
{ }

String::String(const char *s)
        :str_(new char[strlen(s) + 1])
{
    ::strcpy(str_, s);
}


String::String(const String &s)
        :str_(s.str_)
{

}


String::~String()
{
    delete str_; 
}


int main(int argc, const char *argv[])
{
    String s("hello");   
    s.print();

    String s2(s);
    s2.print();
}
