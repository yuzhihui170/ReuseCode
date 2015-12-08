#include <pthread.h>
#include <iostream>
#include "Threads.h"

using namespace std;

void* fun1(void *arg) 
{	
	int n= 10;
	while(n--) {
		cout << "thread1" <<endl;
	}
	return ((void *)0);
}

int main(void)
{
	pthread_t tid;
	Thread thread;
	thread.createThread(&tid,fun1,NULL,0);
	sleep(2);
	cout << "mainthread" << tid << endl;
	return 0;
}