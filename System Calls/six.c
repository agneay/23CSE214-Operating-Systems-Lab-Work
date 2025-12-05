#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int x = 5;
    pid_t pid = fork();

    if(pid < 0){
        perror("Error");
        return 1;
    }else if(pid == 0){
        x+= 10;printf("Child (PID=%d): x = %d\n", getpid(), x);
    } else {
        // Parent: modify x differently
        x += 20;
        printf("Parent (PID=%d): child PID=%d, x = %d\n", getpid(), pid, x);
    }
    
    return 0;
}