#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

#define SHM_SIZE 1024

int main(){
	key_t key;
	int shmid;
	char *shared_memory;

	key = ftok("shmfile",65);

	//create shared memory
	shmid = shmget(key,SHM_SIZE,0666 | IPC_CREAT);
	if(shmid == -1){
		perror("Shmget failed");
		exit(1);
	}

	// Attach shared memory
	shared_memory = (char*)shmat(shmid,NULL,0);
	if(shared_memory == (char*)-1){
		perror("shmat failed");
		exit(1);
	}

	pid_t pid = fork();
	if(pid > 0){
		printf("Parent: Writing to shared memory..\n");
		strcpy(shared_memory,"Hello from Parent Process!");

		sleep(2);

		shmdt(shared_memory);
		shmctl(shmid,IPC_RMID,NULL);
	}else if(pid == 0){
		sleep(1);
		printf("Child: Reading from Shared memory...\n");
		printf("Message: %s\n",shared_memory);

		//detach shared memory
		shmdt(shared_memory);
	}else{
		perror("Fork Failed");
		exit(1);
	}


	return 0;
}
