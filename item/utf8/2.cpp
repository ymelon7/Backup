/*************************************************************************
	> File Name: 1.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Fri 21 Nov 2014 05:45:42 PM PST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 *   本例演示了求字节前几位有多少个连续的1
 * 
 *    
 */

int main(int argc, const char *argv[])
{
    unsigned char c = 0xe5;  //1110 0101 
    int cnt = 0;
    while(c & (1 << (7-cnt)))
        ++cnt;
    printf("%d\n", cnt);
    return 0;
}
