#ifndef CONDITION_H
#define CONDITION_H

#include <pthread.h>
#include <boost/noncopyable.hpp>

class MutexLock;

class Condition : boost::noncopyable
{
public:
    Condition(MutexLock &mutex);
    ~Condition();

    void wait();
    void notify();
    void notifyAll();

private:
    pthread_cond_t cond_;
    MutexLock &mutex_;
};


#endif //CONDITION_H
