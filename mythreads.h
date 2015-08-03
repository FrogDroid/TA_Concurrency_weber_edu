#ifndef __MYTHREADS_h__
#define __MYTHREADS_h__

#include <pthread.h>
#include <semaphore.h>

void Pthread_mutex_init(pthread_mutex_t *m, const pthread_mutexattr_t *restrict attr);
void Pthread_mutex_lock(pthread_mutex_t *m);
void Pthread_mutex_unlock(pthread_mutex_t *m);
void Pthread_create(pthread_t *thread, const pthread_attr_t *attr, 	
	       void *(*start_routine)(void*), void *arg);
void Pthread_join(pthread_t thread, void **value_ptr);
void Pthread_cancel(pthread_t thread);
void Sem_wait(sem_t *sem);
void Sem_post(sem_t *sem);
void Sem_init(sem_t *sem, int pshared, unsigned int value);

#endif // __MYTHREADS_h__
