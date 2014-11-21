/*************************************************************************
	> File Name: 2s.c
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Thu 20 Nov 2014 03:34:58 PM PST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

int ticket_cnt = 30;

//used for each thread
typedef struct tag
{
    int thd_id_;
    pthread_mutex_t *p_mutex_;
}DATA, *pDATA;

//thread execute function
void *handler(void *arg)
{
    int thd_id = ((pDATA)arg)->thd_id_;
    pthread_mutex_t *p_mutex = ((pDATA)arg)->p_mutex_;
    
    printf("window %d on! \n", thd_id);

    //start to sell ticket
    while(1)
    {
        pthread_mutex_lock(p_mutex);

        if(ticket_cnt == 0)
        {   
            printf("ticket sold out! \n");
            
            pthread_mutex_unlock(p_mutex);
            free((pDATA)arg);

            return (void *)0;
        }

        ticket_cnt --;
        sleep(rand() % 2 + 1);
        printf("window %d sold a ticket, ticket left %d \n", thd_id, ticket_cnt);

        pthread_mutex_unlock(p_mutex);
        sleep(rand() % 2 +1);
    }
}


int main (int argc, char *argv[])
{
    srand(getpid());

    //init mutex
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL);

    //create threads
    int thd_cnt = atoi(argv[1]);
    pthread_t *p_thd = (pthread_t *)calloc(thd_cnt, sizeof (pthread_t));
    int ix;
    for(ix = 0; ix < thd_cnt; ix ++)
    {
        pDATA p_info = (pDATA)calloc(1, sizeof (DATA)); 
        p_info->thd_id_ = ix;  
        p_info->p_mutex_ = &mutex;

        pthread_create(p_thd + ix, NULL, handler, (void *)p_info);
    }

    printf("joining threads....\n");

    //join each thread
    for(ix = 0; ix < thd_cnt; ix ++)
    {
        pthread_join(p_thd[ix], NULL); 
    }

    pthread_mutex_destroy(&mutex);
    return 0 ;
}
