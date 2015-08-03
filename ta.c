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

/* Some compilers give you a warning */
long int random(void);
void srandom(unsigned int seed);

void *ta_loop(void *param)
{
	//int sleep_time;

	/* seed random generator */
	srandom((unsigned)time(NULL));

	while (1) 
	{
		// .....
	}
	return NULL;
}

void *student_loop(void *param)
{
	// .....
	
	//printf("\n**** Student %d used his %d sessions ****\n\n", *lnumber, HELP_SESSIONS);
	return NULL;
}

/**
 * Initialize all relevant data structures and
 * synchronization objects.
 */
void init()
{

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
