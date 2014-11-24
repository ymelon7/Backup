/*************************************************************************
	> File Name: productorConsumer.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Sat 22 Nov 2014 06:08:48 AM PST
 ************************************************************************/

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <iostream>
#include <queue>

using namespace std;

pthread_mutex_t mutex;
pthread_cond_t full;
pthread_cond_t empty;
queue<int> Q;

void *producer(void *arg)
{
    while(1)
    {
        //lock
        //produce
        //signal
        //unlock

        pthread_mutex_lock(&mutex);

        //judge produce cond
        while(Q.size() >= 12)
        {
            pthread_cond_wait(&empty, &mutex);
        }

        int elem = rand() % 100;
        Q.push(elem);
        cout << "push elem: " << elem << endl;

        pthread_cond_signal(&full);
        pthread_mutex_unlock(&mutex);

        sleep(1);
    }
}


void *consumer(void *arg)
{
    while(1)
    {
        //lock
        //consume
        //signal
        //unlock

        pthread_mutex_lock(&mutex);

        while(Q.empty())
        {
            pthread_cond_wait(&full, &mutex);
        }

        int elem = Q.front();
        Q.pop();
        cout << "get elem: " << elem 
            << " left: " << Q.size() << endl;

        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&mutex);

        sleep(2);
    }
}


int main (int argc, char *argv[])
{
    srand(12433);
    //init
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&full, NULL);
    pthread_cond_init(&empty, NULL);

    //create threads
    pthread_t producers[6];
    pthread_t consumers[11];
    for(int ix = 0; ix < 6; ix ++)
    {
        pthread_create(&producers[ix], NULL, producer, NULL);
    }
    for(int ix = 0; ix < 11; ix ++)
    {
        pthread_create(&consumers[ix], NULL, consumer, NULL);
    }

    //join threads and delete resouce
    for(int ix = 0; ix < 6; ix ++)
    {
        pthread_join(producers[ix], NULL);
    }
    for(int ix = 0; ix < 11; ix ++)
    {
        pthread_join(consumers[ix], NULL);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&full);
    pthread_cond_destroy(&empty);
    return 0 ;
}
