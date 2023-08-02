#include <stdio.h>
#include <stdlib.h>
int i, j;
void binadd(int a[], int b[], int sum[], int n)
{
    int sum1[n], carry = 0;
    for (i = n - 1; i >= 0; i--)
    {
        sum1[i] = (a[i] + b[i] + carry) % 2;
        carry = (a[i] + b[i] + carry) / 2;
    }
    for (i = 0; i < n; i++)
        sum[i] = sum1[i];
}
void checksum(int **data, int temp[][8], int n)
{
    for (i = 1; i < n; i++)
    {
        binadd(data[i - 1], data[i], data[i], 8);
    }
    for (i = 0; i < 8; i++)
    {
        if (data[n - 1][i] == 1)
            temp[n][i] = 0;
        else
            temp[n][i] = 1;
    }
    for (i = 0; i < n + 1; i++)
    {
        for (j = 0; j < 8; j++)
            printf("%d ", temp[i][j]);
    }
    printf("\n");
}
int receiver(int temp[][8], int n)
{
    // int flag = 0;
    for (i = 0; i < n + 1; i++)
    {
        for (j = 0; j < 8; j++)
            printf("%d ", temp[i][j]);
    }
    printf("\n");
    for (i = 1; i < n + 1; i++)
    {
        binadd(temp[i - 1], temp[i], temp[i], 8);
    }
    for (i = 0; i < 8; i++)
        printf("%d ", temp[n - 1][i]);
    for (i = 0; i < 8; i++)
    {
        // flag++;
        if (temp[n - 1][i] != 1)
            return -1;
    }
    return 1;
}
int main()
{
    int n;
    printf("enter no of bytes:");
    scanf("%d", &n);
    int **data = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        data[i] = (int *)malloc(8 * sizeof(int));

    printf("\nenter data\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 8; j++)
            scanf("%d", &data[i][j]);
    }
    int temp[n + 1][8];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 8; j++)
            temp[i][j] = data[i][j];
    }

    printf("\nsender side\n");
    checksum(data, temp, n);

    printf("\nreceiver side\n");
    int flag = receiver(temp, n);
    if (flag == 1)
        printf("\nno-error\n");
    else
        printf("\nerror\n");
    return 0;
}