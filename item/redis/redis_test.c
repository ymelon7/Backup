/*************************************************************************
	> File Name: redis_test.c
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Sat 22 Nov 2014 07:01:10 PM PST
 ************************************************************************/
#include <stdio.h>  
#include <string.h>  
#include <hiredis.h>  
  
int main()  
{  
    redisContext *c = redisConnect("127.0.0.1", 6379);// ip port  
    if(c->err)  
    {  
        printf("connect error.%s", c->errstr);  
    }  
    else  
    {  
        printf("connected\n");  
    }

    char *value="It's a test";  
    redisReply *reply1 = redisCommand(c, "set foo %s", value);  
    freeReplyObject(reply1);  
    redisReply *reply2 = redisCommand(c, "get foo");  
    printf("foo value:%s\n", reply2->str);  
    freeReplyObject(reply2);  

    redisFree(c);  
    return 0;  
}  

