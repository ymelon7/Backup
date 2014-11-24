/*************************************************************************
	> File Name: 1.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Sat 22 Nov 2014 04:31:16 AM PST
 ************************************************************************/

#include <iostream>

using namespace std;

class Animal
{
    public:
        virtual void run() = 0;  //纯虚函数
};

class Dog : public Animal
{
    public:
        void run()
        {
            cout << "dog could run fastly" << endl; 
        }
};


int main (int argc, char *argv[])
{
    Dog d;
    d.run();
    return 0 ;
}
