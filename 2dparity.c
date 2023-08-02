#include <stdio.h>
void send(int data[][9], int row, int col);
void receive(int data[][9], int row, int col);
int main()
{
    int n, m, i, j;
    printf("\nenter no of bytes:");
    scanf("%d", &n);

    m = 8;
    int row = n + 1; // 3
    int col = m + 1; // 9
    int data[row][col];

    printf("\nenter data\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            data[i][j] = -1;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &data[i][j]);
        }
    }
    send(data, row, col);
    receive(data, row, col);
}
void send(int data[][9], int row, int col)
{
    int count = 0, i, j;
    // row
    for (i = 0; i < row - 1; i++)
    {
        count = 0;
        for (j = 0; j < col - 1; j++)
        {
            if (data[i][j] == 1)
                count++;
        }
        if (count % 2 == 0)
            data[i][col - 1] = 0;
        else
            data[i][col - 1] = 1;
    }
    // column
    count = 0;
    for (j = 0; j < col - 1; j++)
    {
        for (i = 0; i < row - 1; i++)
        {
            if (data[i][j] == 1)
                count++;
        }
        if (count % 2 == 0)
            data[row - 1][j] = 0;
        else
            data[row - 1][j] = 1;
        count = 0;
    }
    // check
    for (j = col - 1; j < col; j++)
    {
        for (i = 0; i < row; i++)
        {
            if (data[i][j] == 1)
                count++;
        }
        if (count % 2 == 0)
            data[row - 1][col - 1] = 0;
        else
            data[row - 1][col - 1] = 1;
    }

    for (i = 0; i < row; i++)
    {
        printf("\n");
        for (j = 0; j < col; j++)
            printf("%d ", data[i][j]);
    }
}
void receive(int data[][9], int row, int col)
{
    printf("\n\nRECEIVER SIDE");

    int sum = 0, flag1 = 0, flag2 = 0, i, j;
    for (j = 0; j < col - 1; j++)
    {
        if (data[row - 1][j] == 1)
            sum++;
    }
    if (sum % 2 == 0)
        flag1 = 1;

    sum = 0;
    for (i = 0; i < row - 1; i++)
    {
        if (data[i][col - 1] == 1)
            sum++;
    }
    if (sum % 2 == 0)
        flag2 = 1;

    if (flag1 == flag2)
        printf("\nNO ERROR\n");
    else
        printf("\nERROR RECEIVER SIDE\n");
}