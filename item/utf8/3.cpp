/*************************************************************************
	> File Name: 3.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Fri 21 Nov 2014 05:59:42 PM PST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
using namespace std;

/*
 *  本例演示了字节的拼接
 */
int main(int argc, const char *argv[])
{
    unsigned char c1 = 0xe6;
    unsigned char c2 = 0x9d;
    unsigned char c3 = 0xa8;

    
    uint32_t c = 0;
    c = c1;
    c = (c << 8) + c2;
    c = (c << 8) + c3;
    printf("%x\n", c & 0xffffff);

    //
    printf("%x \n", c1);
    printf("%x\n", c);
    return 0;
}
