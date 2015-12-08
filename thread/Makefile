SRC = Threads.cpp main.cpp
CC = g++
CCFLAGS = -g -Wall -O0
INCLUDES = 
LIBS = -lpthread

main:$(SRC)
	$(CC) -o $@ $^ $(CCFLAGS) $(INCLUDES) $(LIBS) 

%.o : %.c
	$(CC) -c $< $(CCFLAGS)
				
clean:
	rm -rf test *.o