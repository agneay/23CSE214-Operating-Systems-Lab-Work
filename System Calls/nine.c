#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(){
    int status;
    pid_t pid;

    pid = fork();

    if(pid < 0){
        perror("Fork Failed");
        exit(1);
    }
    if(pid == 0){
        printf("Child: PID = %d exiting with status 7\n",getpid());
        exit(7);
    }else{
        wait(&status);
        if(WIFEXITED(status)){
            printf("Parent: Child Exite normally with status = %d\n",WEXITSTATUS(status));
        }else{
        printf("Parent: Child did not exit normally \n");
        }
    }
    return 0;
}