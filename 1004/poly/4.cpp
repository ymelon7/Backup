/*************************************************************************
	> File Name: 4.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Sat 22 Nov 2014 01:21:41 AM PST
 ************************************************************************/

#include <iostream>

using namespace std;

class Animal
{
    public:
        virtual void run()
        {
            cout << "run..." << endl;
        }
};

class Cat : public Animal
{
    public:
        void run()
        {
            cout << "miao..." << endl;
        }
};

class Dog : public Animal
{
    public:
        void run()
        {
            cout << "wang..." << endl;
        }
};


int main (int argc, char *argv[])
{
    Cat c;
    Dog d;

    Animal *pa = &c;
    pa->run();

    pa = &d;
    pa->run();
}
