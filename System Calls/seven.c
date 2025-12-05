#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    pid_t pid = fork();

    if(pid < 0){
        perror("Fork Failed");
        exit(1);
    }else if(pid == 0){
        printf("Child PID = %d, PPID = %d. Sleeping 5 seconds...\n",getpid(),getppid());
        sleep(5);
        printf("Child: PID = %d Exiting\n",getpid());
        exit(0);
    }
    else{
        printf("Parent: PID = %d, created child %d. Sleeping 2 seconds...\n",getpid(),pid);
        sleep(2);
        printf("Parent: PID = %d, exiting withouth knowing child status.\n",getpid());
        exit(0);
    }
    return 1;
}