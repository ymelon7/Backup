/*************************************************************************
	> File Name: priority.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Thu 13 Nov 2014 05:18:14 AM PST
 ************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;


struct Score
{
    int score_;
    string name_;

    Score(int score, const string name)
        :score_(score), name_(name)
    { }
};


class Cmp
{
public:
    bool operator() (const Score &s1, const Score &s2)
    {
        return s1.score_ < s2.score_;
    }
};


int main(int argc, const char *argv[])
{
    priority_queue<Score, vector<Score>, Cmp> q;
    
    q.push(Score(67, "zhangsan"));
    q.push(Score(88, "lisi"));
    q.push(Score(34, "wangwu"));
    q.push(Score(99, "foo"));
    q.push(Score(0, "bar"));

    while(!q.empty())
    {
        cout << q.top().name_ << " : " 
              << q.top().score_ << endl;
        q.pop();
    }

    return 0;
}
