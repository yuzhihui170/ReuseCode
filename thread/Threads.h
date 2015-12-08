#include <pthread.h>

class Thread {
public:
	Thread();
	~Thread();
	int createThread(pthread_t *threadId, void *(*entryFunction)(void *), void *arg, size_t stacksize);
};