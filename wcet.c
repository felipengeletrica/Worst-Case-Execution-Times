/*
 *  worst-case execution time (WCET).
 *
 *  Created on: 20 de April de 2021
 *  Author: felipevargas
 */

/* INCLUDE */
#include "wcet.h"


const var_wcet system_time()
{
	 // Start measuring time
    struct timeval begin;
    gettimeofday(&begin, 0);

	long seconds = begin.tv_sec;
    long microseconds = begin.tv_usec;
    double elapsed = (seconds + microseconds*1e-6) * 1000;

	return elapsed;
}

/**
 * @brief Init Calculate Worst-Case Executions time
 * 
 * @param wcet_execution_time_st 
 */
void WorstCaseExeTimeInit(st_wcet_execution_time *wcet_execution_time_st)
{
	wcet_execution_time_st->min = MAX_VALUE;
	wcet_execution_time_st->med = 0;
	wcet_execution_time_st->max = 0;
	wcet_execution_time_st->timestamp_mills = system_time();
}

/**
 * @brief Calculate Worst-Case Executions time
 * 
 * @param device_st 
 */
void WorstCaseExeTime(st_wcet_execution_time *wcet_execution_time_st)
{

	var_wcet currentMillis = system_time();

	//printf("currentMillis %ld\n", currentMillis);
	
	/* Filter initial measures WCET */
	if(currentMillis > TIME_INIT_WCET_MEASURE)
	{
		/* Calculate elapsed minimum 1 ms */
		if ((currentMillis - wcet_execution_time_st->timestamp_mills) > 0)
		{
			/* Now elapsed time */
			wcet_execution_time_st->med = (currentMillis - wcet_execution_time_st->timestamp_mills);

			/* Minimum time */
			if(wcet_execution_time_st->med < wcet_execution_time_st->min)
			{
				wcet_execution_time_st->min = wcet_execution_time_st->med;
			}
			/* Maximum time */
			if(wcet_execution_time_st->med > wcet_execution_time_st->max)
			{	
				wcet_execution_time_st->max = wcet_execution_time_st->med;
			}
		
			/* Save timestamp */
			wcet_execution_time_st->timestamp_mills = currentMillis;
		}
	}
	else
	{
		wcet_execution_time_st->min = UINT32_MAX;
		wcet_execution_time_st->med = 0;
		wcet_execution_time_st->max = 0;
		wcet_execution_time_st->timestamp_mills = system_time();
	}
}
