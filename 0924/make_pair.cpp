/*************************************************************************
	> File Name: make_pair.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Thu 13 Nov 2014 07:20:36 AM PST
 ************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//生成一个pair对象的三种方式,
int main(int argc, const char *argv[])
{
    vector<pair<string, int> > vec;

    pair<string, int> word;
    word.first = "hello";
    word.second = 12;
    vec.push_back(word);

    pair<string, int> word2("world", 12);
    vec.push_back(word2);
   
    //notice make_pair's diff way to use
    vec.push_back(make_pair<string, int>("foo", 3));

    vec.push_back(make_pair("bar", 9)); 
   
    string s("hehe");
    int ival = 14;
    vec.push_back(make_pair(s, ival));

    return 0;
}

