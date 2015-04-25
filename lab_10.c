#include<stdio.h>
void main()
{
  int pn,i,p_w,k,temp,m,l;
  p_w=0;
  printf("\nEnter the number of process:");
  scanf("%d",&pn);
  int b[pn],w[pn],t_ar[pn],p[pn];
  for(i=0;i<pn;i++)
  	{
  		printf("\nEnter burst time for process %d:",i+1);
  		scanf("%d",&b[i]);
  		
  	}
  int min =100;
  int flag[pn];
  for(i=0;i<pn;i++)
  flag[i]=0;
  int index;
 for(i=0;i<pn;i++)
{
min = 1000;
	for(k=0;k<pn;k++)
	{
		if(flag[k]!=1 && min>b[k])
		{
			min = b[k];
			index = k;
		}
		
	}
	w[index]=p_w;
  		t_ar[index]=w[index]+b[index];
		p_w+=b[index];
		flag[index]=1;
		printf("\n Process: %d	   burst time = %d	    wait time = %d       turnaround time = %d\n",index+1,b[index],w[index],t_ar[index]);
	
} 
getchar();
 getchar();
  
}
