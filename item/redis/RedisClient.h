#ifndef REDIS_CLIENT_H
#define REDIS_CLIENT_H

#include <boost/noncopyable.hpp>
#include <stdint.h>
#include <hiredis.h>
#include <string>

class RedisClient : boost::noncopyable
{
public:
    RedisClient(const std::string &ip, uint16_t port);
    ~RedisClient();

    void setKeyValue(const std::string &key, const std::string &value);
    std::pair<std::string, bool> getValueByKey(const std::string &key);

private:
    redisContext *connect_;
};


















#endif //REDIS_CLIENT_H
