/*************************************************************************
	> File Name: 2.c
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Wed 19 Nov 2014 06:52:56 AM PST
 ************************************************************************/

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
int i = 0;

void *handler(void *arg)
{
    int ix;
    for(ix = 0; ix < 10000; ix ++)
    {
        pthread_mutex_lock(&mutex);

        i ++;

        pthread_mutex_unlock(&mutex);
    }
}


int main (int argc, char *argv[])
{
    pthread_t thd1, thd2, thd3;

    pthread_mutex_init(&mutex, NULL);
    pthread_create(&thd1, NULL, handler, NULL);
    pthread_create(&thd2, NULL, handler, NULL);
    pthread_create(&thd3, NULL, handler, NULL);

    printf("joining thread......\n");

    pthread_join(thd1, NULL);
    pthread_join(thd2, NULL);
    pthread_join(thd3, NULL);

    pthread_mutex_destroy(&mutex);

    printf("i = %d \n", i);
    return 0 ;
}
