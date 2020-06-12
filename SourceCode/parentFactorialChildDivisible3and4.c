/*Write a C programme. The parent process should read a number from user. Create a child process. Parent process should display the factors of the given number. The child process should print the numbers divisible by both 3 and 4 up to the number entered.*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main(){
	int pid;
	int n;
	printf("Enter a number \n");
	scanf("%d",&n);
	pid=fork();
	if(pid==0){
		//Executing child process
		printf("The numbers divisible by 3 and 4 are: \n");
		for (int num = 0; num < n; num++) {       
		    if (num % 3 == 0 && num % 4 == 0) 
		        printf("%d ",num); 
              } 
		printf("\n");
	}
	else{
		//Parent process execution
		printf("Factors of the given number are: \n");
		for (int i=1;i<=n;i++)
            		if (n%i==0) 
                	printf("%d ",i);
		printf("\n");

	}
}
