#include "Consumer.h"
#include "Buffer.h"
#include <iostream>

Consumer::Consumer(Buffer &buffer)
    :buffer_(buffer)
{

}

void Consumer::run()
{
    while(1)
    {
        int elem = buffer_.pop();

        std::cout << "get a elem: " << elem << std::endl; //run have error, NULL sometimes
        sleep(3);  
    }
}

