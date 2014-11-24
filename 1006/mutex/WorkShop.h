#ifndef WORK_SHOP_H
#define WORK_SHOP_H

#include <boost/noncopyable.hpp>
#include <vector>
#include "Buffer.h"

class Producer;
class Consumer;

class WorkShop : boost::noncopyable
{
public:
    WorkShop(size_t bufferSize,
             size_t producerSize,
             size_t consumerSize);
    ~WorkShop();

    void startWorking();

private:
    size_t bufferSize_;
    Buffer buffer_;

    size_t producerSize_;
    size_t consumerSize_;
    std::vector<Producer *> producers_;
    std::vector<Consumer *> consumers_;
};

#endif //WORK_SHOP_H
