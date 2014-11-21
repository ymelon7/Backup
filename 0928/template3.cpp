/*************************************************************************
	> File Name: template.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Wed 19 Nov 2014 12:09:29 AM PST
 ************************************************************************/

#include <iostream>

using namespace std;

template <typename T1, typename T2>
 T1 max(const T1 &a, const T2 &b)
{
    return (a > b) ? a : b;
}

int main (int argc, const char *argv[])
{
    cout << ::max(5, 4.5) <<endl;
}
