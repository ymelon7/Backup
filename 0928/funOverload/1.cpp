/*************************************************************************
	> File Name: 1.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Wed 19 Nov 2014 01:26:30 AM PST
 ************************************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int &max(const int &a, const int &b)
{
    cout << "version 1" << endl;
    return a > b ? a : b;
}

template <typename T>
const T &max(const T &a, const T &b)
{
    cout << "version 2" << endl;
    return a > b ? a : b;
}

template <typename T>
const T &max(const T &a, const T &b, const T &c)
{
    cout << "version 3" << endl;
    return ::max(::max(a, b), c);
}

int main(int argc, const char *argv[])
{
    ::max(7, 42, 68);  //3 
    ::max(7.0, 43.5);  //2    
    ::max('a', 'b');   //1   2 
    ::max(7, 42);      //1     
    ::max<>(7, 42);    //2 
    ::max<double>(7, 42);  //2  
    ::max('a', 42.7);   //1 
}
