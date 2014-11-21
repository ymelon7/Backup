/*************************************************************************
	> File Name: inherit3.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Fri 21 Nov 2014 07:09:17 AM PST
 ************************************************************************/

#include <iostream>

using namespace std;

class Base
{
    public:
        Base() { cout << "base" << endl; }
        ~Base() { cout << "~base" << endl; }
};

class Other
{
    public:
        Other() { cout << "other" << endl; }
        ~Other() { cout << "~other" << endl; }
};

class Derived : public Base
{
    public:
        Derived() { cout << "derived" << endl; }
        ~Derived() { cout << "~derived" << endl; }

    private:
        Other other_;
};


int main (int argc, char *argv[])
{
    Derived tmp;

    return 0 ;
}
