#include<stdio.h>
#include<sys/types.h>
void main(){
int pid;
printf("Parent process \n");
pid =fork();
if(pid==0){
printf("I am child \n");
printf("My pid child is %d \n",getpid());
printf("My parents pid is %d \n", getppid());
}
else if(pid > 0){
printf(" I am parent process \n");
printf("The process id of child is %d \n",pid);
printf("My pid parent is %d \n",getpid());
}
}
