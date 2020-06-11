#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#define SHMSZ 20
void main(){
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
s=shm;

int n;
n=*shm;
printf("The number %d",n);
int fact=1;
for(int i=1;i<=n;i++){
fact*=i;
}
shm++;
*shm=fact;
shm++;
*shm='#';
printf("Bye");

}

