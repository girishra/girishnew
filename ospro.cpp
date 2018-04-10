#include<stdio.h>
struct processes
{
char pro_name;
int a_t,b_t,ct,w_t,ta_t,priority,b_t1;
}pro[10],pro1[10];
int main()
{
struct processes tmp;
int i,time=0,t1,t2,bu_t=0,larger,lmt,count=0,k,pf2=0,lmt2,n,position,j,flg=0,y;
float w_t=0,ta_t= 0,avg_w_t,avg_ta_t;
printf("\nTotal Number of Process:\n");
scanf("%d",&lmt);
n=lmt;
for(i=0;i<lmt;i++)
{
printf("\nname of process:-");
fflush(stdin);
scanf("%c",&pro[i].pro_name);
printf("\nDetails For processor %c:\n",pro[i].pro_name);
printf("what is Arrival Time:-");
scanf("%d",&pro[i].a_t);
printf("what is Burst Time:-");
scanf("%d",&pro[i].b_t);
pro[i].b_t1=pro[i].b_t;
printf("what is Priority:\t");
scanf("%d",&pro[i].priority);
}
printf("\nwhat is Quantum time for Fixed priority queue:-");
scanf("%d",&t1);
printf("\nwhat is Quantum  time for Round Robin queue:-");
scanf("%d",&t2);
printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
for(i=0;i<lmt;i++)
{
position=i;
for(j=i+1;j<lmt;j++)
{
if(pro[j].a_t<pro[position].a_t)
position=j;
}
tmp=pro[i];
pro[i]=pro[position];
pro[position]=tmp;
}
time=pro[0].a_t;
for(i=0;lmt!=0;i++)
{
while(count!=t1)
{
count++;
if(pro[i].a_t<=time)
{
for(j=i+1;j<lmt;j++)
{
if(pro[j].a_t==time&&pro[j].priority<pro[i].priority)
{
pro1[pf2]=pro[i];
pf2++;
for(k=i;k<lmt-1;k++)
pro[k]=pro[k+1];
lmt--;
count=0;
i=j-1;
j--;
}
}
}
time++;
pro[i].b_t--;
if(pro[i].b_t==0)
{
pro[i].ta_t=time-pro[i].a_t;
pro[i].w_t=pro[i].ta_t-pro[i].b_t1;
printf("%c\t|\t%d\t|\t%d\n",pro[i].pro_name,pro[i].ta_t,pro[i].w_t);
w_t+=time-pro[i].a_t-pro[i].b_t1;
ta_t+=time-pro[i].a_t;
for(k=i;k<lmt-1;k++)
pro[k]=pro[k+1];i--;
lmt--;
count=t1;break;
}
}
count=0;
if(pro[i].b_t!=0)
{
pro1[pf2]=pro[i];
pf2++;
for(k=i;k<lmt-1;k++)
pro[k]=pro[k+1];
lmt--;
}
if(i==lmt-1)
i=-1;
}
lmt2=pf2;
for(count=0;lmt2!=0;)
{
if(pro1[count].b_t<=t2&&pro1[count].b_t>0)
{
time+=pro1[count].b_t;
pro1[count].b_t=0;
flg=1;
}
else if(pro1[count].b_t>0)
{
pro1[count].b_t-=t2;
time+=t2;
}
if(pro1[count].b_t==0&&flg==1)
{
lmt2--;
pro1[count].ta_t=time-pro1[count].a_t;
pro1[count].w_t=pro1[count].ta_t-pro1[count].b_t1;
printf("%c\t|\t%d\t|\t%d\n",pro1[count].pro_name,pro1[count].ta_t,pro1[count].w_t);
ta_t+=time-pro1[count].a_t;
w_t+=time-pro1[count].a_t-pro1[count].b_t1;
for(k=count;k<lmt2;k++)
pro1[k]=pro1[k+1];count--;
flg=0;
}
if(count==lmt2-1)
count=0;
else
count++;
}
printf("\nAvg Wt Time= %f\n",w_t*1.0/n);
printf(" \nAvg Ta Time = %f",ta_t*1.0/n);
}
