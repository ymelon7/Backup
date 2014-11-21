/*************************************************************************
	> File Name: map3.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Fri 14 Nov 2014 03:29:10 AM PST
 ************************************************************************/

#include <iostream>
#include <map>

using namespace std;

int main (int argc, char *argv[])
{
    map<string, int> m;
    
    m["beijing"] = 35;
    m["nanjing"] = 2;
    m["chongqing"] = 89;
    m["guagnzhou"] = 79;

    cout << m.size() << endl;

    cout << m["shanghai"] << endl;

    cout << m.size() << endl;
    
    //three ways to traverse the map with c++11
    for(const auto &tmp : m) //auto const &tmp; correct
    {
        cout << tmp.first << ": " << tmp.second << endl;
    }

    cout << "---------------" << endl;

    for(auto it = m.begin(); it != m.end(); it ++)
    {
        cout << it->first << ": " << it->second << endl;
    }

    cout << "---------------" << endl;

    for(const pair<string, int> &tmp : m) 
    //pair<string, int> const &tmp;corect
    //pair<string, int> &const tmp;error
    //conclusion: const int kval == int const kval;??
    {
        cout << tmp.first << ": " << tmp.second << endl;
    }
}
