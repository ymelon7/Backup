/*************************************************************************
	> File Name: editDistance.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Fri 21 Nov 2014 01:25:11 AM PST
 ************************************************************************/

#include <iostream>
using namespace std;

namespace
{
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

    
    
    }

}




int main (int argc, char *argv[])
{

    return 0 ;
}
