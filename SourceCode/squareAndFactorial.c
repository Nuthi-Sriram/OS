#include<stdio.h>
#include<sys/types.h>
void main(){
int pid;
int n;
scanf("%d",&n);
pid=fork();
if(pid==0){
int fact=1;
for(int i=1;i<=n;i++){
fact*=i;
}
printf("%d \n",fact);
}
else{
printf("%d \n",n*n);
}
}
