#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#define SHMSZ 20
void main(){
int shmid;
key_t key;
char *shm,*s;
key=5672;
if((shmid=shmget(key,SHMSZ,IPC_CREAT | 0666))<0){
printf("Shared memory not created");
}
if((shm=shmat(shmid,NULL,0))==(char *) -1){
printf("Error");
}
s=shm;
for(char c='a';c<='z';c++)
*s++=c;
*s=NULL;
while(*shm!='#')
sleep();
printf("Bye");

}
