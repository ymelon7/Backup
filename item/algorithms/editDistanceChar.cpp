/*************************************************************************
	> File Name: editDistanceChar.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Fri 21 Nov 2014 12:21:24 AM PST
 ************************************************************************/

#include <iostream>
#include <string>
#include <assert.h>
#include <string.h>

using namespace std;

namespace
{
    inline int minThribble(int a, int b, int c)
    {
        int ret = (a < b) ? a : b; 
        ret = (c < ret) ? c : ret;

        return ret;
    }
}

int editDistanceChar(const string &a, const string &b);

int main (int argc, char *argv[])
{
    cout << "please input two strings" << endl;
    
    string a;
    string b;
    while(cin >> a >> b)
    {
        int ret = editDistanceChar(a, b);
        
        cout << "edit distance of a and b: " << ret << endl; 
    }
}


int editDistanceChar(const string &a, const string &b)
{
    assert(a.size() < 100 && b.size() < 100);

    int memo[100][100];
    ::memset(memo, 0, sizeof memo);
    
    //L(i, 0) = i
    for(size_t i = 0; i <= a.size(); i ++)
    {
        memo[i][0] = i;
    }
    //L(0,j) = j
    for(size_t j = 0; j <= b.size(); j ++)
    {
        memo[0][j] = j;
    }

    for(size_t i = 1; i <= a.size(); i ++)
    {
        for(size_t j = 1; j <= b.size(); j ++)
        {
            if(a[i - 1] == b[j - 1])
            {
                memo[i][j] = memo[i-1][j-1];
            }
            else
            {
                int t1 = memo[i-1][j];
                int t2 = memo[i][j-1];
                int t3 = memo[i-1][j-1];
                
                memo[i][j] = minThribble(t1, t2, t3) + 1;
            } 
        }  
    }
     
    return memo[a.size()][b.size()];
}
