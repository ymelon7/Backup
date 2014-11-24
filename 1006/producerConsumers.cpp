/*************************************************************************
	> File Name: producerConsumers.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Sat 22 Nov 2014 11:04:58 PM PST
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
        //notify
        //unlock
        
        pthread_mutex_lock(&mutex);

        while(Q.size() >= 10)
        {
            pthread_cond_wait(&empty, &mutex);
        }
        int elem = rand() % 100;
        Q.push(elem);
        cout << "push elem: " << elem << endl;
        
        pthread_cond_signal(&full); //could problem
        
        pthread_mutex_unlock(&mutex);

        sleep(1);
    }
}


void *consumer(void *arg)
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        
        while(Q.empty())
        {
            pthread_cond_wait(&full, &mutex);
        } 
        int elem = Q.front();
        Q.pop();
        cout << "get elem: " << elem
            << "  left: " << Q.size() << endl;

        pthread_cond_signal(&empty);

        pthread_mutex_unlock(&mutex);
        
        sleep(2);
    }
}


int main (int argc, char *argv[])
{
    srand(123454);

    //init 
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&full, NULL);
    pthread_cond_init(&empty, NULL);

    //create threads
    pthread_t producers[3];
    pthread_t consumers[5];
    for(int ix = 0; ix < 3; ix ++)
    {
        pthread_create(&producers[ix], NULL, producer, NULL);
    }
    for(int ix = 0; ix < 5; ix ++)
    {
        pthread_create(&consumers[ix], NULL, consumer, NULL);
    }

    //join threads and delete resource
    for(int ix = 0; ix < 3; ix ++)
    {
        pthread_join(producers[ix], NULL);
    }
    for(int ix = 0; ix < 5; ix ++)
    {
        pthread_join(consumers[ix], NULL);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&full);
    pthread_cond_destroy(&empty);
    return 0 ;
}
