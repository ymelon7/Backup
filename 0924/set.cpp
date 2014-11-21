/*************************************************************************
	> File Name: set.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Fri 14 Nov 2014 04:29:47 AM PST
 ************************************************************************/

#include <iostream>
#include <set>

using namespace std;

int main (int argc, char *argv[])
{
    set<int> t;

    for(int cnt = 1; cnt < 20; cnt ++)
    {
        t.insert(cnt);
        t.insert(cnt);
    }

    cout << t.size() << endl;
}
