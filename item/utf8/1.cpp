/*************************************************************************
	> File Name: 1.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Fri 21 Nov 2014 05:49:57 PM PST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char *argv[])
{
    string s = "严";

    for(size_t ix = 0; ix != s.size(); ++ix)
    {
            printf("%x\n", s[ix] & 0xff);
    }

    //
    cout << "----------" << endl;
    cout << s.size() << endl;
    printf("%x \n", s[0]);
    return 0;
}
