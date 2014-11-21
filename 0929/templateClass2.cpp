/*************************************************************************
	> File Name: templateClass2.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Fri 21 Nov 2014 04:39:08 AM PST
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Test
{
public:
    Test(const T &tmp) :data_(tmp) { }

    void print() const;

private:
    T data_;
};

template <typename T>
void Test<T>::print() const
{
    cout << data_ << endl;
}


int main (int argc, char *argv[])
{
    Test<int> t(12);
    t.print();

    Test<string> st("hello");
    st.print();

}
