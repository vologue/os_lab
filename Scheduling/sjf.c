#include<stdio.h>
int main()
{
    int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
        p[i]=i+1;  
    }
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    wt[0]=0;          
    printf("wt: ");
    for(i=0;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
        {
          wt[i]+=bt[j];
        }
        printf("%d      ",wt[i]);
      total+=wt[i];
    }
    avg_wt=(float)total/n;     
    total=0;
    printf("\nTAT: ");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("%d      ",tat[i]);
    }

    avg_tat=(float)total/n; 
    printf("Average Waiting Time:%0.6f",avg_wt);
    printf("\nAverage Turnaround Time:%0.6f",avg_tat);  
    return 0;
}