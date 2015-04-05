#include<stdio.h>
int main()
{
    int n,B_t[20],W_t[20],tat[20],avwt=0,AV_tat=0,i,j;
    printf("Enter number of processes:\n");
    scanf("%d",&n);
    printf("Enter Process Burst Time\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&B_t[i]);
    }

    W_t[0]=0;    //waiting time for first process is 0
    //calculating waiting time
    for(i=1;i<n;i++)
    {
        W_t[i]=0;
        for(j=0;j<i;j++)
            W_t[i]+=B_t[j];
    }
    printf("\nProcess\t\tBurst_Time\tWaiting_Time\tTurnaround_Time");
    //calculating turnaround time
    for(i=0;i<n;i++)
    {
        tat[i]=B_t[i]+W_t[i];
        avwt+=W_t[i];
        AV_tat+=tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d\n",i+1,B_t[i],W_t[i],tat[i]);
    }

    return 0;
}
