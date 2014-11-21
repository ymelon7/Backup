/*************************************************************************
	> File Name: lamda.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Sat 15 Nov 2014 04:36:01 AM PST
 ************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <ctype.h>
using namespace std;

void toUpper(string &s)
{
    for(string::iterator it = s.begin();
            it != s.end();
            ++it)
    {
            if(islower(*it))
                *it = toupper(*it);
    }
}

void print(const string &s)
{
    cout << s;
}



int main(int argc, const char *argv[])
{
    vector<string> vec;
    vec.push_back("beijing");
    vec.push_back("changchun");
    vec.push_back("shijiahzuang");
    vec.push_back("shenyang");
    vec.push_back("dalian");
    vec.push_back("jinan");
    vec.push_back("nanjing");


    for_each(vec.begin(), vec.end(), toUpper);

    for_each(vec.begin(), 
             vec.end(), 
             [](const string &s) { cout << s << endl; });

    return 0;
}
