#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
    printf("Before exec: PID = %d\n",getpid());
    execlp("ls","ls","-l",(char*)NULL);
    perror("execlp failed");
    return 0;
}