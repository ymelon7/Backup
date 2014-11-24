#ifndef CONSUMER_G
#define CONSUMER_H

#include "Thread.h"

class Buffer;

class Consumer : public Thread
{
public:
    Consumer(Buffer &buffer);

    void run();

private:
    Buffer &buffer_;
};

#endif //CONSUMER_H
