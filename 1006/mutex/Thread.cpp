#include "Thread.h"

Thread::Thread()
    :threadId_(0),
     isRunning_(false)
{

}

Thread::~Thread()
{
    if(isRunning_)
    {
        pthread_detach(threadId_);
    }
}

void *Thread::runInThread(void *arg)
{
    Thread *pt = static_cast<Thread *>(arg);
    pt->run();

    return NULL;

}

void Thread::start()
{
    pthread_create(&threadId_, NULL, Thread::runInThread, this);    
    isRunning_ = true;
}

void Thread::join()
{
    assert(isRunning_);

    pthread_join(threadId_, NULL);
    isRunning_ = false;
}

