#include<sys/types.h>
#include<sys/ipc.h>
#include<stdlib.h>
#include<sys/shm.h>
#define SHMSZ 20
#include<stdio.h>

void main()
{
int shmid;
key_t key;
int *shm , *s;
key = 125;

if( (shmid = shmget(key,SHMSZ,IPC_CREAT | 0666)) < 0)
{
printf("Memory not created");
}

if(( shm = shmat(shmid,NULL,0)) == (int*)-1)
{
printf("Error");
}

int a=*shm;
int fact = 1;
for( int i = 2 ; i <= a ; i++ )
{
fact *= i;
}
printf("%d",fact);
*shm='#';
}
