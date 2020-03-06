#include<stdio.h>
#include<sys/types.h>
void main(){
int pid1,pid2;
printf("Parent process executing \n");
pid1=fork();
pid2=fork();
printf("Hai \n");
}
