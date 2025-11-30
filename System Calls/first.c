#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    pid_t pid;

    printf("Before fork: I am the original Process. PID = %d\n",getpid());
    pid = fork(); // created a new process

    if(pid < 0){
        // fork failed
        perror("FORK FAILED");
        return 1;
    }else if(pid  == 0){
        // Child Process
        printf("Child Process");
        printf("Parent PID = %d",getppid());
        printf("Child PID = %d",getpid());
    }else {
        // Parent process
        printf("PARENT PROCESS:\n");
        printf("  Parent PID = %d\n", getpid());
        printf("  Child PID  = %d\n", pid);
    }
    return 0;
}