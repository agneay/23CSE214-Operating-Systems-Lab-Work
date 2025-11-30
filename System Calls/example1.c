#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(int argvc,char **argv ){
    pid_t pid;
    pid = fork();

    if(pid == -1){
        perror("fork failed!");
        exit(1);
    }

    if(pid == 0){
        printf("Child\n");
        fflush(stdout);
    }else{
        wait(NULL); // wait till the child exits
        printf("Parent\n");
        fflush(stdout);
    }
    exit(0);
}