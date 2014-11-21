/*************************************************************************
	> File Name: map.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Thu 13 Nov 2014 07:50:01 AM PST
 ************************************************************************/
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, const char *argv[])
{
    map<string, int> m;

    m["beijing"] = 2000;
    m["shenzhen"] = 1000;
    m["shanghai"] = 1500;
    m["hongkong"] = 500;
    m["hangzhou"] = 880;

    for(map<string, int>::iterator it = m.begin();
                          it != m.end();
                          ++it)
    {
        cout << it->first << ": " << it->second << endl;
    }
    
    cout << "-----------------" << endl;

    for(map<string, int>::const_iterator it = m.begin();
                          it != m.end();
                          ++it)
    {
        cout << it->first << ": " << it->second << endl;
    }
}
