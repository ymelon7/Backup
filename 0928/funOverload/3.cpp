/*************************************************************************
	> File Name: 3.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Wed 19 Nov 2014 04:34:03 AM PST
 ************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
const T &max(const T &a, const T &b)
{
    cout << "template" << endl;
    return a > b ? a : b;
}

template <typename T>
const T &max(const T &a, const T &b, const T &c)
{
    ::max(::max(a, b), c);
}

//如果想在三个参数的max版本中调用这个函数, 必须把它放在前面
const int &max(const int &a, const int &b)
{
    cout << "mark" << endl;
    return a > b ? a : b;
}

int main(int argc, const char *argv[])
{
    ::max(1, 2, 3);
}
