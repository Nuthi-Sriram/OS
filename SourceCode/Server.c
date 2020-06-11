#include<sys/types.h>
#include<sys/ipc.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/shm.h>
#define SHMSZ 20

void main()
{
char c;
int shmid;
key_t key;
int *shm,*s;

key=125;

if((shmid=shmget(key,SHMSZ,IPC_CREAT | 0666))<=0)
printf("Error");

else if((shm=shmat(shmid,NULL,0))==(int*)-1)
printf("ERROR");

s=shm;
printf("Enter a number");
int a;
scanf("%d",&a);

*s=a;
shm=s++;

while(*shm!='#')
sleep();
printf("BYE");



}
