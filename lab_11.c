#include<stdio.h>
void main()
{
int Proc_Number,i,Pre_Wait,k,temp,m,l;
printf("\nEnter the nunmber of process:");
scanf("%d",&Proc_Number);
int exec[Proc_Number],start[Proc_Number],deadline[Proc_Number], flag[Proc_Number];
for(i=0;i<Proc_Number;i++)
flag[Proc_Number] = 0;
Pre_Wait = 0;
 for(i=0;i<Proc_Number;i++)
 {
 	printf("\nEnter start time,exec time and deadline for process %d:",i+1);
 	scanf("%d %d %d",&start[i],&exec[i],&deadline[i]);
 }
	
 int time_quatum=0;
 int end_false=1;
 int nearest_deadline=10000;
 int index=-1;
 int count=0;
 while(end_false)
 {
for(i=0;i<Proc_Number;i++)
	{
	if(start[i] == time_quatum || exec[index] == 0)
		{
 		if(flag[i] != 1)
			{
			if(((deadline[i]-time_quatum)-exec[i])<smallest_slack)
				{
				smallest_slack=(deadline[i]-time_quatum);
				index=i;
				}
			}
		}
		
		
	}
	if(exec[index] == 0)
			{
				nearest_deadline = 10000;
				index=-1;
			}
	if(index!=-1)
	{
	printf("\n from time quantum %d to %d, proc %d",time_quatum,time_quatum+1,index+1);
	exec[index]--;
	if(exec[index] == 0)
	{
		flag[index]=1;
		count++;
	}
	}
	if(count == Proc_Number)
		end_false = 0;
	time_quatum++;
 }
 
}