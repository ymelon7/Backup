/*************************************************************************
	> File Name: 2.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Sat 22 Nov 2014 04:45:27 AM PST
 ************************************************************************/

#include <iostream>

using namespace std;

class Base
{
    public:
        Base() { cout << "Base" << endl; }
       virtual ~Base() { cout << "~Base" << endl; }
};

class Derived : public Base
{
    public:
        Derived() { cout << "Derived" << endl; }
        ~Derived() { cout << "~Derived" << endl; }
};


int main (int argc, char *argv[])
{
    Base *pb = new Derived;
    
    delete pb;

    
    return 0 ;
}
