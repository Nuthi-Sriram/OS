#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main(){
int pid;
pid=fork();
if(pid==0){
execlp("/home/sriram/Documents/work/OS/SourceCode/numberOfDigits","numberOfDigits",NULL);
}
else{
wait(NULL);
printf("Child process has finished executing \n");
}
}

