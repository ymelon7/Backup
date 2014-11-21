/*************************************************************************
	> File Name: 2.c
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Wed 19 Nov 2014 07:32:42 AM PST
 ************************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int ticket_cnt = 20;

//used for each thread
typedef struct tag
{
    int thd_id_;
    pthread_mutex_t *p_mutex_;
}DATA, *pDATA;


//each thread execute functon
void *handler(void *arg)
{
    int thd_id = ((pDATA)arg)->thd_id_;
    pthread_mutex_t *p_mutex = ((pDATA)arg)->p_mutex_;
    
    printf("A window on ! : %d \n", thd_id);
    int tmp;

    while(1)
    {
        pthread_mutex_lock(p_mutex);

        if(ticket_cnt == 0)
        {
            printf("Ticket sold out ! \n");

            pthread_mutex_unlock(p_mutex);
            free((pDATA)arg);

            return (void *)0; 
        }

        tmp = ticket_cnt - 1;
        sleep(rand() % 3 + 1);
        ticket_cnt = tmp;

        printf("Window %d sold a ticket ! Ticket left %d\n", thd_id, ticket_cnt);

        pthread_mutex_unlock(p_mutex);
        sleep(rand() % 3 + 1);  
    }
}


int main (int argc, char *argv[])
{
    srand(getpid());

    //init
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL);

    //create threads
    int thd_cnt = atoi(argv[1]);
    pthread_t *p_thd = (pthread_t *)calloc(thd_cnt, sizeof (pthread_t));
    int ix;
    for(ix = 0; ix < thd_cnt; ix ++)
    {
        pDATA p = (pDATA)calloc(1, sizeof (DATA));
        p->thd_id_ = ix;
        p->p_mutex_ = &mutex;

        pthread_create(p_thd + ix, NULL, handler, (void *)p);
    }

    //join threads
    printf("joining threads.....\n");
    for(ix = 0; ix < thd_cnt; ix ++)
    {
        pthread_join(p_thd[ix], NULL);  
    }
    
    pthread_mutex_destroy(&mutex);
    return 0 ;
}
