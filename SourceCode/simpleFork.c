#include<stdio.h>
#include<sys/types.h>
void main(){
int pid;
pid=fork();
if(pid==0){
printf("I am child \n");
}
else{
printf("I am parent \n");
}
}
