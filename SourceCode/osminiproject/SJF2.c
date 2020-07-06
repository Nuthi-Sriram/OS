#include<stdio.h>

void main()
{
int i,name[10]={1,2,3,4,5,6,7,8,9,10},n,mintime,x=1,btime=0,sort=0;
int burst_time[10],temp,j,arrival_time[10],waiting_time[10],turnaround_time[10],ta=0,sum=0;
float wavg=0,tavg=0,tsum=0,wsum=0;
printf("\nEnter the number of processes :");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter the arrival time of %d process :",i+1);
scanf(" %d",&arrival_time[i]);
printf("Enter the burst time of %d process :",i+1);
scanf(" %d",&burst_time[i]);
}
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(arrival_time[i]<arrival_time[j])
{
temp=name[j];
name[j]=name[i];
name[i]=temp;
temp=arrival_time[j];
arrival_time[j]=arrival_time[i];
arrival_time[i]=temp;
temp=burst_time[j];
burst_time[j]=burst_time[i];
burst_time[i]=temp;
sort=sort+1;
}
}
}
if(sort>0)
{
for(j=0;j<n;j++)
{
btime=btime+burst_time[j];
mintime=burst_time[x];
for(i=x+1;i<n;i++)
{
if (btime>=arrival_time[i] && burst_time[i]<mintime)
{
temp=name[x];
name[x]=name[i];
name[i]=temp;
temp=arrival_time[x];
arrival_time[x]=arrival_time[i];
arrival_time[i]=temp;
temp=burst_time[x];
burst_time[x]=burst_time[i];
burst_time[i]=temp;
}
}
x++;
}
}
else{
   
    for(i=0;i<n;i++)
    {
    for(j=0;j<n;j++)
    {
    if(burst_time[i]<burst_time[j])
    {
    temp=name[j];
    name[j]=name[i];
    name[i]=temp;
    temp=arrival_time[j];
    arrival_time[j]=arrival_time[i];
    arrival_time[i]=temp;
    temp=burst_time[j];
    burst_time[j]=burst_time[i];
    burst_time[i]=temp;
    }
    }
    }
}
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        if((burst_time[i]==burst_time[j])&&(arrival_time[i]<arrival_time[j]))
        {
           temp=name[j];
           name[j]=name[i];
           name[i]=temp;
           temp=arrival_time[j];
           arrival_time[j]=arrival_time[i];
           arrival_time[i]=temp;
           temp=burst_time[j];
           burst_time[j]=burst_time[i];
           burst_time[i]=temp;
        }
    }
}
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        if((arrival_time[i]==arrival_time[j])&&(burst_time[i]<burst_time[j]))
        {
           temp=name[j];
           name[j]=name[i];
           name[i]=temp;
           temp=arrival_time[j];
           arrival_time[j]=arrival_time[i];
           arrival_time[i]=temp;
           temp=burst_time[j];
           burst_time[j]=burst_time[i];
           burst_time[i]=temp;
        }
    }
}

waiting_time[0]=0;
for(i=1;i<n;i++)
{
sum=sum+burst_time[i-1];
if(sum>arrival_time[i])
   waiting_time[i]=sum-arrival_time[i];
else
   waiting_time[i]=0;
wsum=wsum+waiting_time[i];
}

wavg=(wsum/n);
for(i=0;i<n;i++)
{
turnaround_time[i]=burst_time[i]+waiting_time[i];
tsum=tsum+turnaround_time[i];
}
tavg=(tsum/n);
printf("\n RESULT:-");
printf("order of execution is: ");
for(int i=0;i<n;i++)
{
    printf("p%d  ",name[i]);
}
printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
for(i=0;i<n;i++)
{
printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d",name[i],burst_time[i],arrival_time[i],waiting_time[i],turnaround_time[i]);
}
printf("\n\nAverage waiting time is : %f",wavg);
printf("\nAverage turnaround time is : %f",tavg);
}
