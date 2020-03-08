#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#define SHMSZ 20
void main(){
int shmid;
key_t key;
char *shm,*s;
key=5678;
if((shmid=shmget(key,SHMSZ,666))<0){
printf("Shared memory not created");
}
if((shm=shmat(shmid,NULL,0))==(char *) -1){
printf("Error");
}
for(s=shm;*s!=NULL;s++){
printf("%c",*s);
}
*shm='#';
}
