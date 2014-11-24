/*************************************************************************
	> File Name: editDistance.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Fri 21 Nov 2014 01:25:11 AM PST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stdint.h>
#include <assert.h>
#include <string.h>

using namespace std;

namespace
{

int minThribble(int a, int b, int c)
{
    int ret = (a < b) ? a : b;
    ret = (ret < c) ? ret : c;

    return ret;
}

int getLenOfUTF8(unsigned char c)  //why undigned char?
{
    int cnt = 0;
    while(c & (1 << (7 - cnt)))
    {
        cnt ++; 
    }

    return cnt;
}

//把字符串解析成uint32_t数组
void parseUTF8String(const string &s, vector<uint32_t> &vec)
{
    vec.clear();

    for(size_t ix = 0; ix != s.size(); ix ++)
    {
        assert(ix < s.size());

        int len = getLenOfUTF8(s[ix]);
        uint32_t t = (unsigned char)s[ix];
        if(len > 1)
        {
            -- len;

            //拼接剩余的字节
            while(len --)
            {
                t = (t << 8) + (unsigned char)s[++ix];
            }  
        }

        vec.push_back(t); 
    }  
}


int editDistanceUint32(const vector<uint32_t> &w1, 
        const vector<uint32_t> &w2)
{
    int len_a = w1.size();
    int len_b = w2.size();

    int memo[100][100];
    ::memset(memo, 0, sizeof memo);

    //L(i,0) = i
    for(int i = 0; i <= len_a; i ++)
    {
        memo[i][0] = i; 
    }
    for(int j = 0; j <= len_b; j ++)
    {
        memo[0][j] = j;
    } 

    for(int i = 1; i <= len_a; i ++)
    {
        for(int j = 1; j <= len_b; j ++)
        {
            if(w1[i-1] == w2[j-1])
            {
                memo[i][j] = memo[i-1][j-1];
            }
            else
            {
                int t1 = memo[i-1][j];
                int t2 = memo[i][j-1];
                int t3 = memo[i-1][j-1];

                memo[i][j] = minThribble(t1, t2,t3) + 1; 
            } 
        } 

    }

    return memo[len_a][len_b];     
}

int editDistance(const string &a, const string &b)
{
    vector<uint32_t> w1, w2;

    parseUTF8String(a, w1);
    parseUTF8String(b, w2);
    
    return editDistanceUint32(w1, w2);
}

}




int main (int argc, char *argv[])
{
    string a;
    string b;

    cout << "please enter two strings:" << endl;
    while(cin >> a >> b)
    {
        cout << "edit distance: " 
            << editDistance(a, b) << endl;
    }
}
