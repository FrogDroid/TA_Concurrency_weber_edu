/**
 * General structure of the teaching assistant.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include "mythreads.h"
#include "ta.h"

/* I need some conditional variables to keep track of what's going on. */
int sleeping = 1; //indicates ta sleeping.

/* Some compilers give you a warning */
long int random(void);
void srandom(unsigned int seed);

void *ta_loop(void *param)
{

	/* seed random generator */
	srandom((unsigned)time(NULL));

	while (1) 
	{
		Pthread_mutex_lock(&mutex_lock);
		sleeping = 1;
		printf("\n TA is going to sleep. \n");
		Pthread_mutex_unlock(&mutex_lock);
		Sem_wait(&students_sem);
		//I shall help them.
		help_student(2);
		//check for students in the hall
		while(waiting_students > 0)
		{
			//grab student
			Sem_post(&ta_sem);
			//help student
			Pthread_mutex_lock(&mutex_lock);
			//student goes into office.
			waiting_students--;
			Pthread_mutex_unlock(&mutex_lock);
			//student gets help
			help_student(2);
		}
	}
	return NULL;
}

void *student_loop(void *param)
{
	// .....
	//student is a thread
	srandom((unsigned)time(NULL)); //seed for each student.
	int usedSessions = 0;
	int seated = 0;
	while(usedSessions <= HELP_SESSIONS)
	{
	//Check if the TA is asleep -- we'll assume any time the semaphore is available it means the TA is napping. 
	//because the TA micro naps like batman.
		if(!sleeping)
		{
			//if I'm already in the seat, I don't need to do anything.
			if(!seated)
			{
				if(waiting_students < NUM_OF_SEATS)
				{
					//oh look, there is a chair which means I should check on the TA
					//grab the seat
					seated = 1;
					Pthread_mutex_lock(&mutex_lock); //critical section starts here. we may update the number of seats taken up.
					waiting_students++;
					Pthread_mutex_unlock(&mutex_lock);	
					printf("\n Student %d has taken a seat. Seats taken: %d\n", *(int*)param, waiting_students);
					//okay we have our seat now, let's wait on the TA.
					Sem_wait(&ta_sem); 
					//The TA then helps the student.
					seated = 0;
					usedSessions++;
				}
				else
				{
					hang_out(*(int*)param, rand());
				}
			}	
		}
		else if(sleeping){
			//he's sleeping and no one else has woken him up.
			printf("\n Student %d found the TA sleeping and is waking him up.\n", *(int*)param);
			Pthread_mutex_lock(&mutex_lock);
			sleeping = 0;
			Pthread_mutex_unlock(&mutex_lock);
			Sem_post(&students_sem);
			//no get help
			Sem_wait(&ta_sem);
			usedSessions++;
		}
		printf("\n student %d has %d sessions remaining. \n", *(int*)param, HELP_SESSIONS - usedSessions);
	}	
	printf("\n**** Student %d used his %d sessions ****\n\n", *(int*)param, HELP_SESSIONS);
	return NULL;
}

/**
 * Initialize all relevant data structures and
 * synchronization objects.
 */
void init()
{
	//init the lock
	Pthread_mutex_init(&mutex_lock, NULL); 
	
	//init the semaphores
	Sem_init(&students_sem, 0, 0);
	Sem_init(&ta_sem, 0, 0);
	return;
}

/**
 * Simulate a student hanging out
 */
void hang_out(int lnumber, int sleep_time) 
{
	printf("\tStudent %d hanging out for %d seconds\n",lnumber,sleep_time);
	sleep(sleep_time);
}

/*  Helping students */
void help_student(int sleep_time)
{
	printf("Helping a student for %d seconds waiting students = %d\n",sleep_time, waiting_students);
	
	sleep(sleep_time);
}


