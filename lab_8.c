#include<stdio.h>
#include<malloc.h>
void main()
{
int M_b[10],p[5],x[10],i,j,ch,min,max,k,cnt,I_F=0,E_F=0,y[10]={0};
char n[10];

M_b[0]=195;
M_b[1]=75;
M_b[2]=695;
M_b[3]=115;
M_b[4]=220;
M_b[5]=295;
M_b[6]=395;
M_b[7]=95;
M_b[8]=175;
M_b[9]=895;
p[0]=100;
p[1]=275;
p[2]=170;
p[3]=340;
p[4]=500;
for(i=0;i<10;i++)
{
x[i]=M_b[i];
}
for(i=0;i<10;i++)
{
n[i]=(char*)malloc(M_b[i]*1000);
}
printf("1.FIRST FIT\n");
printf("2.BEST FIT\n");
printf("3.WORST FIT\n");
printf("4.NEXT FIT\n");
printf("Enter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1: //FIRST
i=0;
while(i!=5)
{
for(j=0;j<10;j++)
{
if(M_b[j]>=p[i])
{
M_b[j]=M_b[j]-p[i];
y[j]=M_b[j];
n[j]=(char*)malloc(p[i]*1000);
break;
}
}
i++;
}
break;
case 2: //BEST
cnt=0;
b: for(i=0;i<9;i++)
{
min=x[i];
for(j=i+1;j<10;j++)
{
if(min>x[j])
{
min=x[j];
x[j]=x[i];
x[i]=min;
}
}
}
while(cnt!=5)
{
for(j=0;j<10;j++)
{
if(x[j]>=p[cnt])
{
for(k=0;k<10;k++)
{
if(M_b[k]==x[j])
{
M_b[k]=M_b[k]-p[cnt];
y[k]=M_b[k];
break;
}
}
x[j]=x[j]-p[cnt];
n[j]=(char*)malloc(p[i]*1000);
break;
}
}
cnt++;
goto b;
}
break;
case 3: //WORST
cnt=0;
a: for(i=0;i<9;i++)
{
max=x[i];
for(j=i+1;j<10;j++)
{
if(max<x[j])
{
max=x[j];
x[j]=x[i];
x[i]=max;
}
}
}
while(cnt!=5)
{
for(j=0;j<10;j++)
{
if(x[j]>=p[cnt])
{
for(k=0;k<10;k++)
{
if(M_b[k]==x[j])
{
M_b[k]=M_b[k]-p[cnt];
y[k]=M_b[k];
break;
}
}
x[j]=x[j]-p[cnt];
n[j]=(char*)malloc(p[cnt]*1000);
break;
}
}
cnt++;
goto a;
}
break;
case 4: //NEXT
i=0;
k=0;
while(i!=5)
{
for(j=k;j<10;j++)
{
if(M_b[j]>=p[i])
{
k=j;
M_b[j]=M_b[j]-p[i];
y[j]=M_b[j];
n[j]=(char*)malloc(p[i]*1000);
break;
}
if(j==9)
{
k=0;
}
}
i++;
}
break;
default:
printf("Wrong choice\n");
break;
}
for(i=0;i<10;i++)
{
printf("%d\n",M_b[i]);
}
for(i=0;i<10;i++)
{
E_F=E_F+M_b[i];
}
for(i=0;i<10;i++)
{
I_F=I_F+y[i];
}
printf("Internal fragmentation %d\n",I_F);
printf("External fragmentation %d\n",E_F);
}
