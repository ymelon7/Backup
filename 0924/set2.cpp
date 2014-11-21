/*************************************************************************
	> File Name: set2.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Fri 14 Nov 2014 04:35:01 AM PST
 ************************************************************************/

#include <iostream>
#include <set>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main (int argc, char *argv[])
{
    srand(getpid());

    set<int> se;
    for(int cnt = 0; cnt < 20; cnt ++)
    {
        se.insert(rand() % 100);
    }

    for(auto i : se)
    {
        cout << i << " ";
    }
    cout << endl;
}
