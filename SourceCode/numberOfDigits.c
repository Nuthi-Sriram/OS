#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main(){
int n;
printf("Enter a number \n");
scanf("%d",&n);
int count=0;
while(n>0){
n=n/10;
count++;
}
printf("The count of the number of digits is %d \n", count);
}
