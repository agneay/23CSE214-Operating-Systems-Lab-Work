#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    pid_t pid;

    pid = fork();

    if(pid < 0){
        perror("fork failed");
        return 1;
    }else if (pid == 0){
        printf("CHILD PROCESS");
        printf("CHILD  PID : %d",getpid());
        printf("PARENT PID: %d",getppid());
    }else{
        printf("This is parent process");
        printf("CHILD PID: %d",pid);
        printf("Parrent PID: %d",getppid());
    }
    return 0;
}