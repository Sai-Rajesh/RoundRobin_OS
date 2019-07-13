#include<stdio.h> 
int main() 
{ 
  int count,j=0,n,time,remain,tq1,tq2; 
  int wt[10],tat[10],at[10],bt[10],rt[10],t[10];
  int total_turnaround_time=0,total_waiting_time=0;
  float atat=0,awt=0; 
  int i,m,k=0;
  int max,l;
  printf("Enter Total Process:\t \n"); 
  scanf("%d",&n); 
  remain=n; 
  for(i=0;i<n;i++) 
  { 
    printf("Enter Arrival Time(ascending order) and Burst Time for Process P[%d]:\n",i+1); 
    scanf("%d",&at[i]); 
    scanf("%d",&bt[i]); 
    rt[i]=bt[i]; 
  } 
  time=at[0]; 
printf("Enter Time Quantum: for 1st iteration\t\n");
  scanf("%d",&tq1); 
   
 	for(i=0;i<n;i++){
		if(at[i]<=time && rt[i]!=0)
		{
			printf("the process P[%d] is running at present\n",i+1);
			rt[i] -=tq1;
			time+=tq1;
			if(rt[i]<=0)
			{
				printf("the process P[%d] is completed at 1st iteration \n",i+1);
				t[i]=time;
				rt[i]=0;
				tat[i]=time-bt[i];
				wt[i]=tat[i]-at[i];
				printf("%d   %d",tat[i],wt[i]);
			}
			
		}
	}
	printf("Enter Time Quantum: for 2nd iteration\t\n");
  scanf("%d",&tq2);
  for(i=0;i<n;i++)
  {
		if(at[i]<=time && rt[i]!=0)
		{
			printf("the process P[%d] is running at present\n",i+1);
			rt[i]-=tq2;
			time+=tq2;
			if(rt[i]<=0)
			{
				printf("the process P[%d] is completed at 2nd iteration\n",i+1);
				t[i]=time;
				rt[i]=0;
					tat[i]=time-bt[i];
				wt[i]=tat[i]-at[i];
			}
		}	
	}
	 printf("\n\nProcess\t|Turnaround Time|Waiting Time|Time completed\n\n"); 
	for(i=0;i<n;i++)
	{
		printf("P[%d]%d\t%d\t%d\t\n",i+1,tat[i],wt[i],t[i]);
	}
	for(i=0;i<n;i++)
	{
		total_turnaround_time +=tat[i];
		total_waiting_time +=wt[i];
	}
	atat=total_turnaround_time/n;
	awt=total_waiting_time/n;
	printf("total waiting time is %d\n",total_waiting_time);
	printf("total turnaround time is %d",total_turnaround_time);
	 printf("Average turn around time is%f\n",atat);
	 printf("Average wating time is %f\n",awt);
}
