#include "Producer.h"
#include "Buffer.h"
#include <stdlib.h>
#include <iostream>

Producer::Producer(Buffer &buffer)
    :buffer_(buffer)
{
    srand(133443);
}

void Producer::run()
{
    while(1)
    {
        int elem = rand() % 100;
        buffer_.push(elem);
        
        std::cout << "push a elem: " << elem << std::endl;
        sleep(2);
    }
}

