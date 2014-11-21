/*************************************************************************
	> File Name: disallowCopy.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Sat 15 Nov 2014 07:16:27 AM PST
 ************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Test
{
public:
    Test() {}
    ~Test() {}
private:
    Test(const Test &t);
    void operator=(const Test &t);
};


int main(int argc, const char *argv[])
{
    Test t;

    Test t2(t);
    
    Test t3;
    t3 = t;
}
