#include "RedisClient.h"
#include <muduo/base/Logging.h>
#include <string.h>

using namespace muduo;

RedisClient::RedisClient(const std::string &ip, uint16_t port)
{
    connect_ = redisConnect(ip.c_str(), port);

    if(connect_ == NULL || connect_->err)
    {
        LOG_ERROR << "redis connected host: " << ip << "port: " << port;
        exit(EXIT_FAILURE);
    }
    else
    {
        LOG_INFO << "redis connect successfully";
    }
}

RedisClient::~RedisClient()
{
    redisFree(connect_);
    LOG_INFO << "redis connected closed";
}

void RedisClient:: setKeyValue(const std::string &key, const std::string &value)
{

    redisReply *reply = static_cast<redisReply *>(redisCommand(connect_, "set %s %s", key.c_str(), value.c_str()));

    LOG_DEBUG << "redis setkeyvalue key: " << key << "  value: " << value;
    freeReplyObject(reply);
}

std::pair<std::string, bool> RedisClient::getValueByKey(const std::string &key)
{
    LOG_DEBUG << "redis get value by key: " << key;

    redisReply *reply = static_cast<redisReply *>(redisCommand(connect_, "get %s", key.c_str()));

    std::pair<std::string, bool> ret;
    if(reply->type == REDIS_REPLY_NIL)
    {
        ret.second = false;
        LOG_DEBUG << "redis getValueByKey key: " << key << " key is not exits";
    }
    else
    {
        ret.second = true;
        ret.first = reply->str;
        LOG_DEBUG << "redis getValueByKey key: " << key << "  value: " << ret.first;
    }

    freeReplyObject(reply);

    return ret;
}

