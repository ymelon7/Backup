#include "Buffer.h"

Buffer::Buffer(size_t size)
    :full_(mutex_),
     empty_(mutex_),
     size_(size)
{

}

void Buffer::push(int val)
{
    //lock
    //wait
    //push
    //unlock
    //signal
    
    {
        MutexLockGuard lock(mutex_);  //初始化上锁，并保证只要上锁出了作用域就一定能解锁，实现自动化解锁

        while(queue_.size() >= size_)
        {
            empty_.wait();
        } 
        
       queue_. push(val);
    }
    
    full_.notify();
}

int Buffer::pop()
{
    int tmp = 0;

    {
        MutexLockGuard lock(mutex_);

        while(queue_.empty())
        {
            full_.wait();
        } 
        
        tmp = queue_.front();
        queue_.pop();
    }
    
    empty_.notify();

    return tmp;
}

bool Buffer::empty() const
{
    MutexLockGuard lock(mutex_);

    return queue_.empty();
}

size_t Buffer::size() const
{
    MutexLockGuard lock(mutex_);

    return queue_.size();
}

