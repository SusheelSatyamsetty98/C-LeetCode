#include <stdio.h>
#include <pthread.h>

pthread_cond_t cond;
pthread_mutex_t mutex;
int itr = 0;

void* even_fn(void* args)
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        
        if(itr%2 != 0 && itr <= 30)
            pthread_cond_wait(&cond, &mutex);
        
        if(itr > 30)
        {
            pthread_mutex_unlock(&mutex);
            pthread_cond_broadcast(&cond);
            break;
        }
        
        if (itr%2 == 0)
            printf("Even : %d\n",itr++);
        
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);
    }
    return NULL;
}

void* odd_fn(void* args)
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        
        if(itr%2 == 0 && itr <= 30)
            pthread_cond_wait(&cond, &mutex);
        
        if(itr > 30)
        {
            pthread_mutex_unlock(&mutex);
            pthread_cond_broadcast(&cond);
            break;
        }
        
        if (itr%2 != 0)
            printf("Odd : %d\n",itr++);
        
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);
    }
    return NULL;
}

int main()
{
    pthread_t even;
    // pthread_attr_t even_attr;
    
    // pthread_attr_init(&even_attr);
    // pthread_attr_setdetachstate(&even_attr,PTHREAD_CREATE_DETACHED);
    // pthread_create(&even,&even_attr,(void*)even_fn, NULL);
    pthread_create(&even,NULL,(void*)even_fn, NULL);
    
    pthread_t odd;
    // pthread_attr_t odd_attr;
    
    // pthread_attr_init(&odd_attr);
    // pthread_attr_setdetachstate(&odd_attr,PTHREAD_CREATE_DETACHED);
    // pthread_create(&odd,&odd_attr,(void*)odd_fn, NULL);
    pthread_create(&odd,NULL,(void*)odd_fn, NULL);
    
    pthread_join(even, NULL);
    pthread_join(odd, NULL);
    // while(itr <= 30);
    printf("End");
    
    return 0;
}
