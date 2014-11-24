/*************************************************************************
	> File Name: testRedisClient.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Sun 23 Nov 2014 06:25:55 PM PST
 ************************************************************************/
#include "RedisClient.h"
#include <iostream>
#include <muduo/base/Logging.h>

using namespace muduo;

int main (int argc, char *argv[])
{
    Logger::setLogLevel(Logger::DEBUG);

    RedisClient client("localhost", 6379);

    std::string key;
    std::string value;
    while(std::cin >> key >> value)
    {
        client.setKeyValue(key, value);
    }

    std::cin.clear();

    while(std::cin >> key)
    {
        std::pair<std::string, bool> ret = client.getValueByKey(key);
        
        if(ret.second)
        {
            std::cout << "key: " << key << " value: " << ret.first << std::endl;
        } 
        else
        {
            std::cout << "key: " << key << " key is not exits" << std::endl;
        
        } 
    }
    return 0 ;
}
