/*************************************************************************
	> File Name: inherit2.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Fri 21 Nov 2014 06:55:16 AM PST
 ************************************************************************/

#include <iostream>

using namespace std;

class Parent
{
    public:
        Parent() { cout << "parent" << endl; }
        ~Parent() { cout << "~parent" << endl; }
};


class Child : public Parent
{
    public:
        Child() { cout << "child" << endl; } 
        ~Child() { cout << "~child" << endl; }
};


int main (int argc, char *argv[])
{
    Child boy;
    

    Child girl;
    Parent papa;

    papa = girl;

    boy = papa;
    return 0 ;
}
