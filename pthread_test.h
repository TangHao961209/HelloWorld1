/*
 * pthread_test.h
 *
 *  Created on: 2020年5月8日
 *      Author: tanghao
 */
#include <pthread.h>
#ifndef PTHREAD_TEST_H_
#define PTHREAD_TEST_H_
typedef struct{
  pthread_mutex_t mutex;
}mct_pipeline_thread_data_t;

int  checknum(void *data);
void*  checknum1();



#endif /* PTHREAD_TEST_H_ */
