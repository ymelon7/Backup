/*************************************************************************
	> File Name: map2.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Thu 13 Nov 2014 08:00:43 AM PST
 ************************************************************************/

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main (int argc, char *argv[])
{
    map<int, string> pr;
    pr[23] = "hello";
    pr[3] = "world";
    pr[2] = "how";
    pr[15] = "are";
    pr[98] = "foo";
    pr[1] = "bar";

    for(const pair<int, string> &p : pr)
    {
        cout << p.first << ": " << p.second << endl;
    } 

    cout << "---------------" << endl;

    for(map<int, string>::const_iterator it = pr.begin();
            it != pr.end();
            it ++)
    {
        cout << it->first << ": " << it->second << endl;
    }
    
    cout << "---------------" << endl;

    for(auto it = pr.begin();
             it != pr.end();
             it ++)
    {
        cout << it->first << ": " << it->second << endl;
    }

}
