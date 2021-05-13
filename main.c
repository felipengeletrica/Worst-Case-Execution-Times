/**
 * @file main.c
 * @author Felipe Vargas(felipeng.eletrica@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <unistd.h>
#include "wcet.h"


void display(st_wcet_execution_time *wcet_execution_time_st)
{
    int count = 0;

    for(count=0; count<WCET_MAX_SIZE; count++)
    {
        printf("--------------------------------------\n");
        printf("Minimum time: %ld\n", wcet_execution_time_st->min);
        printf("Actual time: %ld\n", wcet_execution_time_st->med);
        printf("Maximum time: %ld\n", wcet_execution_time_st->max);
    }
}

int main(void)
{
    static const st_wcet_execution_time *wcet_execution_time_st[WCET_MAX_SIZE];

    /* Init WCET calculate time */
	WorstCaseExeTimeInit((st_wcet_execution_time *) &(wcet_execution_time_st[WCET_OPERATIONAL]));
	WorstCaseExeTimeInit((st_wcet_execution_time *) &(wcet_execution_time_st[WCET_INTERRUPT]));

    printf("WCET PROGRAM\n");

    sleep(5);
    /* Calculate latency */
	WorstCaseExeTime((st_wcet_execution_time *) &wcet_execution_time_st[WCET_INTERRUPT]);

    sleep(1);
    /* Calculate latency */
	WorstCaseExeTime((st_wcet_execution_time *) &wcet_execution_time_st[WCET_INTERRUPT]);
    display((st_wcet_execution_time *) &wcet_execution_time_st);


    sleep(2);
    /* Calculate latency */
	WorstCaseExeTime((st_wcet_execution_time *) &wcet_execution_time_st[WCET_INTERRUPT]);
    display((st_wcet_execution_time *) &wcet_execution_time_st);

    return 0;
}