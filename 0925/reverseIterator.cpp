/*************************************************************************
	> File Name: reverseIterator.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Fri 14 Nov 2014 06:22:07 AM PST
 ************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[])
{
    vector<int> coll;

    for (int i = 0; i <= 9 ; i++) 
    {
            coll.push_back(i);
    }

    vector<int>::iterator pos;
    pos = find(coll.begin(), coll.end(), 5);

    cout << "pos: " << *pos << endl; 

    vector<int>::reverse_iterator rpos(pos);
    cout << "rpos: " << *rpos << endl; 
}

