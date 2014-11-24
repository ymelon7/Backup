/*************************************************************************
	> File Name: 3.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Fri 21 Nov 2014 11:43:46 PM PST
 ************************************************************************/

#include <iostream>

class Noncopyable
{
    public:
        Noncopyable() {  }
        ~Noncopyable() {  }

    private:
        Noncopyable(const Noncopyable &arg);
        void operator=(const Noncopyable &arg);
};

class Test : Noncopyable
{


};


int main (int argc, char *argv[])
{
    Test t;

    Test t2(t);

    Test t3;
    t3 = t;
}
