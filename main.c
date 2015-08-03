#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include "mythreads.h"
#include "ta.h"

/*  Globals */
pthread_t ta;
pthread_t students[NUM_OF_STUDENTS];
/*  Prototypes */
void create_students();
void create_ta();

/* Main Program 
 * DO NOT MODIFY THIS PROGRAM
 * ONLY ta.c 
 */
int main(void)
{
	int i;

	init();

	create_ta();

	create_students();

	for (i = 0; i < NUM_OF_STUDENTS; i++)
		Pthread_join(students[i], NULL);

	/* when all students have finished, we will cancel the TA thread */	
	Pthread_cancel(ta);
	printf("\n**** TA finished helping all students\n.\t He is a happy person ;)\n");

	return 0;
}

/* init() should be defined in ta.c */

/* create student trheads*/
void create_students()
{
	for (int i = 0; i < NUM_OF_STUDENTS; i++) {
		Pthread_create(&students[i], 0, student_loop, (void *)&student_id[i]);
	}
}

/* create ta trheads*/
void create_ta()
{
	Pthread_create(&ta, 0, ta_loop, 0);
}
