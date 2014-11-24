#ifndef THREAD_H
#define THREAD_H

#include <pthread.h>
#include <boost/noncopyable.hpp>

class Thread : boost::noncopyable
{
public:
    Thread();
    ~Thread();

    void start();
    void join();

    virtual void run() = 0;

    pthread_t getThreadId() const
    { return threadId_; }

private:
    static void *runInThread(void *arg);

    pthread_t threadId_;
    bool isRunning_;
};

#endif //THREAD_H
