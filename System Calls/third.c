#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    pid_t pid;

    pid = fork();

    if(pid < 0){
        perror("Fork failed");
        return -1;
    }

    printf("Message from PID = %d with PPID = %d\n",getpid(),getppid());
    return 0;
}