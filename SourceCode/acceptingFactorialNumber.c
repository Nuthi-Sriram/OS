#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#define SHMSZ 20
void main(){
int n;
int shmid;
key_t key;
int *shm,*s;
key=5900;
if((shmid=shmget(key,SHMSZ,IPC_CREAT | 0666))<0){
printf("Shared memory not created");
}
if((shm=shmat(shmid,NULL,0))==(int *) -1){
printf("Error");
}
printf("Enter a number of which you want to find the factorial of \n");
scanf("%d",&n);
*shm=n;
shm++;
shm++;
while(*shm!='#')
sleep(1);
printf("%d",*shm);
}

