#include<stdio.h>
void paritychecker(int data[],int n);
void printval(int data[],int n);
int main()
{
        int n,i;
        printf("enter no of bits:");
        scanf("%d",&n);
        int data[n+1];
        for(i=0;i<n;i++)
           scanf("%d",&data[i]);
        paritychecker(data,n);
        printval(data,n)
}
void paritychecker(int data[],int n)
{
        int count=0,i;
        for(i=0;i<n;i++)
        {
                if(data[i]==1)
                        count++;
        }
        if(count%2==0)
        {
                printf("\nEVEN PARITY\n");
                data[n] = 0;
        }
        else
        {
                printf("\nODD PARITY\n");
                data[n] = 1;
        }
}
void printval(int data[],int n)
{
        int i;
        for(i=0;i<=n;i++)
           printf("%d",data[i]);
}