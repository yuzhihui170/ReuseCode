#include <string.h>
#include <stdio.h>
#include "Threads.h"

Thread::Thread() 
{
}

Thread::~Thread()
{
}

int Thread::createThread(pthread_t *threadId, void *(*entryFunction)(void *), void *arg, size_t stacksize) 
{
	pthread_attr_t attr; 
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED); //以分离状态启动线程
	if (stacksize) {
        pthread_attr_setstacksize(&attr, stacksize);
    }
	pthread_t thread;
	int result = pthread_create(&thread, &attr, entryFunction, arg);
	pthread_attr_destroy(&attr);
	if(result != 0) {
		printf("[File:%s, Line:%d] %s",__FILE__,__LINE__,strerror(result));
		return 0;
	}
	if(threadId != NULL) {
		*threadId = thread;
	}
	return 1;
}