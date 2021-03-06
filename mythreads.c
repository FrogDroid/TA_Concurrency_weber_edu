#include <pthread.h>
#include <semaphore.h>
#include <assert.h>
#include <sched.h>
#include "mythreads.h"
// Mutex Locks
void Pthread_mutex_init(pthread_mutex_t *m, const pthread_mutexattr_t *restrict attr)
{
	int rc = pthread_mutex_init(m, attr);
	assert(rc == 0);
}
void Pthread_mutex_lock(pthread_mutex_t *m)
{
	int rc = pthread_mutex_lock(m);
	assert(rc == 0);
}

void Pthread_mutex_unlock(pthread_mutex_t *m)
{
	int rc = pthread_mutex_unlock(m);
	assert(rc == 0);
}
// Pthreads 
void Pthread_create(pthread_t *thread, const pthread_attr_t *attr, 	
		void *(*start_routine)(void*), void *arg)
{
	int rc = pthread_create(thread, attr, start_routine, arg);
	assert(rc == 0);
}

void Pthread_join(pthread_t thread, void **value_ptr)
{
	int rc = pthread_join(thread, value_ptr);
	assert(rc == 0);
}
 
void Pthread_cancel(pthread_t thread)
{
	int rc =  pthread_cancel(thread);
	assert(rc == 0);

}
 
void Sem_wait(sem_t *sem)
{
	int rc = sem_wait(sem);
	assert(rc == 0);
}
void Sem_post(sem_t *sem)
{
	int rc = sem_post(sem);
	assert(rc == 0);
}

void Sem_init(sem_t *sem, int pshared, unsigned int value)
{
	int rc = sem_init(sem, pshared,value);
	assert(rc == 0);
}
