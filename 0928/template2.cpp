/*************************************************************************
	> File Name: template.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Wed 19 Nov 2014 12:09:29 AM PST
 ************************************************************************/

#include <iostream>

using namespace std;

template <typename T>
const T &max(const T &a, const T &b)
{
    return (a > b) ? a : b;
}

int main (int argc, const char *argv[])
{
    //1
    cout << ::max(3, static_cast<int>(3.8)) << endl;
    //2
    cout << ::max<int>(3, 3.9) << endl;
}
