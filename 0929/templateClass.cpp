/*************************************************************************
	> File Name: templateClass.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Fri 21 Nov 2014 04:24:58 AM PST
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Test
{
public:
    Test(const T &tmp) :data_(tmp) { }

    void print() const
    { cout << data_ << endl; }

private:
    T data_;
};


int main (int argc, char *argv[])
{
    Test<int> t(12);
    t.print();

    Test<string> st("hello");
    st.print();
}
