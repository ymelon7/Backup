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
    int ival = 2;
    cout << ::max(3, ival) << endl;

    double a = 89.3;
    double b = 89.32;
    cout << ::max(a, b) << endl;

    string s1("hello");
    string s2("world");
    cout << ::max(s1, s2) << endl;
}
