/*************************************************************************
	> File Name: 1.c
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Mon 24 Nov 2014 04:19:21 AM PST
 ************************************************************************/

#include <stdio.h>

int main (int argc, char *argv[])
{
    int i = 11;
    int const *p = &i;

    p ++;
    printf("%d", *p);
    return 0 ;
}
