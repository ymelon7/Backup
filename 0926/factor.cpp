/*************************************************************************
	> File Name: factor.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Tue 18 Nov 2014 08:28:15 AM PST
 ************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Comp
{
public:
    Comp(int data) : data_(data) { }

    bool operator() (int i)
    {
        return i >= data_;
    }

private:
    int data_;
};


int main(int argc, const char *argv[])
{
    vector<int> vec;

    vec.push_back(99);
    vec.push_back(87);
    vec.push_back(59);
    vec.push_back(43);
    vec.push_back(78);
    vec.push_back(91);

    int num = 90;
    int cnt = 
        std::count_if(vec.begin(), vec.end(), Comp(num));
    cout << cnt << endl;
}
