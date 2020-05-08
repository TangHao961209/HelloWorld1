/*
 * pthread_test.cpp
 *
 *  Created on: 2020年5月8日
 *      Author: tanghao
 */
#include "pthread_test.h"
#include <iostream>
#include <stdio.h>

int checknum(void *data){
	static int i = 0;
	mct_pipeline_thread_data_t *data1 = (mct_pipeline_thread_data_t *) data;
	pthread_mutex_lock(&data1->mutex);
	i++;
	printf("i = %d \n",i);
    pthread_mutex_unlock(&data1->mutex);
	return i;
}

void* checknum1(){
	static int i = 0;
	i++;
	printf("i = %d \n",i);
}



