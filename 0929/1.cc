#include <vector>

class Test
{
public:
    Test() { }
    ~Test() { }

private:
    Test(const Test &);
    void operator=(const Test &);  //why back type void ?
};


int main(int argc, const char *argv[])
{
    //虽然类Test是不可复制和赋值的,但这样定义,编译并不会报错
    std::vector<Test> vec;


    //若在定义这样的语句，编译就会报错了,
    //因为Test的复制构造函数是私有的,即禁止复制,
    //而向vector中放入Test对象时需要复制，所以会报错
    Test t;
    vec.push_back(t);
}






