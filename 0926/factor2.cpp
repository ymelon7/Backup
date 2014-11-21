/*************************************************************************
	> File Name: factor2.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Tue 18 Nov 2014 08:36:16 AM PST
 ************************************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Test
{
public:

    void operator() ()
    {
        cout << "Hello World" << endl;
    }

    void operator() (int i)
    {
        cout << "Hello " << i << endl;
    }
};

int main(int argc, const char *argv[])
{
    Test t;
    t();

    t(99);
    t.operator()(100);
}
