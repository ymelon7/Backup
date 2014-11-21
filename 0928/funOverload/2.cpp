/*************************************************************************
	> File Name: 2.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Wed 19 Nov 2014 04:01:36 AM PST
 ************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

template <typename T>
const T &max(const T &a, const T &b)
{
    return a > b ? a : b;
}

const char * &max(const char * &a, const char * &b)
{
    return ::strcmp(a, b) > 0 ? a : b;
}

template <typename T>
const T &max(const T &a, const T &b, const T &c)
{
    return ::max(::max(a, b), c);
}


int main(int argc, const char *argv[])
{
    ::max(7, 42, 68);

    const char *s1 = "fegfwe";
    const char *s2 = "Fwtfgt";
    const char *s3 = "geryhgr5";
    ::max(s1, s2, s3);         //返回的是一个临时的变量,这里将临时变量的引用返回出去，可能导致错误
}
