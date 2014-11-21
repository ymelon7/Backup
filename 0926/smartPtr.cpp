/*************************************************************************
	> File Name: smartPtr.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Tue 18 Nov 2014 07:09:20 AM PST
 ************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class Test
{
public:

    Test() { cout << "Test " << endl; }
    ~Test() {  cout << "Test ...." << endl; }

    void print() const
    {
        cout << "Test Print ..." << endl;
    }
};

class TestPtr
{
public:
    TestPtr(Test *ptr) :ptr_(ptr) { }
    ~TestPtr() 
    { 
        delete ptr_; 
       cout << "TestPtr destructor..." << endl; 
    }

    Test &operator* ()
    {
        return *ptr_;
    }

    const Test &operator* () const
    {
        return *ptr_;
    }

    Test *operator->()
    {
        return ptr_;   
    }

    const Test *operator->() const
    {
        return ptr_;
    }

private:
    TestPtr(const TestPtr &);
    void operator=(const TestPtr &);

    Test *ptr_;
};



int main(int argc, const char *argv[])
{
    //try
    //{
        //Test *ptr = new Test; 
        TestPtr ptr(new Test);
        (*ptr).print();

        {
            TestPtr ptr2(new Test);
            ptr2->print();  
        }

        cout << "即将抛出异常" << endl;

        //throw runtime_error("错误");
    
    //}
    //catch(...)
    //{
     //   cout << "Catch ..." << endl; 
    //}
}
