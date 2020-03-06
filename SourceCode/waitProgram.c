#include<stdio.h>
#include<sys/types.h>
void main(){
int pid=fork();
if(pid<0){
printf("Fork failed \n");
}
else if(pid==0)
{
execlp("/home/ccuser/Documents/lab/squareAndFactorial","squareAndFactorial",NULL);
}
else{
wait(NULL);
printf("Child Completed");
}
}

