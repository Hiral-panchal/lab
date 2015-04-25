#include<stdio.h>
void main()
{
int pn,i,p_w,k,temp,m,l;
printf("\nEnter the nunmber of process:");
scanf("%d",&pn);
int exec[pn],start[pn],d_l[pn], flag[pn];
for(i=0;i<pn;i++)
flag[pn] = 0;
p_w = 0;
 for(i=0;i<pn;i++)
 {
 	printf("\nEnter start time,exec time and deadline for process %d:",i+1);
 	scanf("%d %d %d",&start[i],&exec[i],&d_l[i]);
 }
	
 int time_quatum=0;
 int end_false=1;
 int smallest_slack=10000;
 int index=-1;
 int count=0;
 while(end_false)
 {
for(i=0;i<pn;i++)
	{
	if(start[i] == time_quatum || exec[index] == 0)
		{
 		if(flag[i] != 1)
			{
			if(((d_l[i]-time_quatum)-exec[i])<smallest_slack)
				{
				smallest_slack=(d_l[i]-time_quatum);
				index=i;
				}
			}
		}
		
		
	}
	if(exec[index] == 0)
			{
				smallest_slack = 10000;
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
	if(count == pn)
		end_false = 0;
	time_quatum++;
 }
 
}
