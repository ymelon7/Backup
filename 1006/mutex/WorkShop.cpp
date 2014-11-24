#include "WorkShop.h"
#include "Producer.h"
#include "Consumer.h"

WorkShop::WorkShop(size_t bufferSize,
                   size_t producerSize,
                   size_t consumerSize)
    :bufferSize_(bufferSize),
     buffer_(bufferSize_),
     producerSize_(producerSize),
     consumerSize_(consumerSize),
     producers_(producerSize_, NULL),
     consumers_(consumerSize_, NULL)
{
    //创建线程
    for(std::vector<Producer *>::iterator it = producers_.begin();
        it != producers_.end();
        it ++)
    {
        *it = new Producer(buffer_);
    }
    for(std::vector<Consumer *>::iterator it = consumers_.begin();
        it != consumers_.end();
        it ++)
    {
        *it = new Consumer(buffer_);
    }
}

WorkShop::~WorkShop()
{
    for(std::vector<Producer *>::iterator it = producers_.begin();
            it != producers_.end();
            it ++)
    {
        delete *it;
    }
    for(std::vector<Consumer *>::iterator it = consumers_.begin();
        it != consumers_.end();
        it ++)
    {
        delete *it;
    } 
}

void WorkShop::startWorking()
{
    for(std::vector<Producer *>::iterator it = producers_.begin();
            it != producers_.end();
            it ++)
    {
        (*it)->start();
    }
    for(std::vector<Consumer *>::iterator it = consumers_.begin();
        it != consumers_.end();
        it ++)
    {
        (*it)->start();
    } 
    
    for(std::vector<Producer *>::iterator it = producers_.begin();
            it != producers_.end();
            it ++)
    {
        (*it)->join();
    }
    for(std::vector<Consumer *>::iterator it = consumers_.begin();
        it != consumers_.end();
        it ++)
    {
        (*it)->join();
    } 
}

