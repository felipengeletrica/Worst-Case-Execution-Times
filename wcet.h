/*
 *  worst-case execution time (WCET).
 *
 *  Created on: 20 de April de 2021
 *  Author: felipevargas
 */

#ifndef WCET_H_
#define WCET_H_

/* INCLUDES */
#include <stdint.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

/* DEFINES */
#define TIME_INIT_WCET_MEASURE 1 * 1000 /* Time wait for measures */
#define MAX_VALUE UINT32_MAX

/* ENUMERATE */
/**
 * @brief Worst Case Execution Times (WCETs)
 *
 */
enum eWCT
{
  WCET_OPERATIONAL,
  WCET_INTERRUPT,
  WCET_MAX_SIZE	
};


typedef uint64_t var_wcet;

/* STRUCT */
//Worst-case execution time (WCET)
typedef struct
{
	var_wcet min;
	var_wcet med;
	var_wcet max;
	var_wcet timestamp_mills;
}__attribute__((__packed__)) st_wcet_execution_time;

/* PROTOTYPES */
void WorstCaseExeTimeInit(st_wcet_execution_time *wcet_execution_time_st);
void WorstCaseExeTime(st_wcet_execution_time *wcet_execution_time_st);
#endif /* WCET_H_ */
