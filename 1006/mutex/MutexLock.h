#ifndef MUTEX_LOCK_H
#define MUTEX_LOCK_H

#include <pthread.h>
#include <boost/noncopyable.hpp>
#include <stdio.h>
#include <stdlib.h>

#define TINY_CHECK(exp) \
    if(!(exp)) \
    {   \
        fprintf(stderr, "File:%s, Line:%d Exp:["#exp"] is true, abort. \n", __FILE__, __LINE__ ); abort();\
    }

class MutexLock : boost::noncopyable
{
public:
    MutexLock();
    ~MutexLock();

    void lock();
    void unlock();
    
    bool isLocking() const { return isLocking_; }
    pthread_mutex_t *getMutexPtr() 
    { return &mutex_; }

private:
pthread_mutex_t mutex_;
bool isLocking_;
};


#endif //MUTEX_LOCK_H
