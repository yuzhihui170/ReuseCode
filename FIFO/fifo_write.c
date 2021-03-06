#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

#define FIFO "myfifo"
#define BUFF_SIZE 1024

void sys_err()
{
	printf("system error : %s\n",strerror(errno));
}

int main(int argc,char* argv[]) {
	char buff[BUFF_SIZE];
    int real_write;
    int fd;

    if(argc<=1){
        printf("Usage: ./fifo_write string\n");
        exit(1);
    }
	memset(buff,0,BUFF_SIZE);
    sscanf(argv[1],"%s",buff);
	//测试FIFO是否存在，若不存在，mkfifo一个FIFO
    if(access(FIFO,F_OK)==-1){
        if((mkfifo(FIFO,0666)<0)&&(errno!=EEXIST)){
            printf("Can NOT create fifo file!\n");
			sys_err();
            exit(1);
        }
    }
	//printf("PIPE_BUF = %ld\n",sysconf(PIPE_BUF));
	//调用open以只写方式打开FIFO，返回文件描述符fd    
    if((fd=open(FIFO,O_WRONLY))==-1){
        printf("Open fifo error!\n");
        exit(1);
    }

	//调用write将buff写到文件描述符fd指向的FIFO中
    if ((real_write=write(fd,buff,BUFF_SIZE))<0) {
        printf("Write into pipe: '%s'.\n", buff);
        exit(1);
    }
    close(fd);
    exit(0);
}