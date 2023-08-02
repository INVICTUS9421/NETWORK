#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int i, j, k;
void sender(int *data, int values[], int count, int parity);
void display(int *data, int count);
void receiver(int *data, int count);
int hamming_rule(int bits);

int main()
{
    int bits;
    printf("\nEnter no of bits:");
    scanf("%d", &bits);
    int parity = hamming_rule(bits);
    int count = parity + bits + 1;

    int values[bits];
    printf("\nEnter data\n");
    for (i = 0; i < bits; i++)
        scanf("%d", &values[i]);

    int *data = (int *)malloc(count * sizeof(int));
    for (i = 0; i < count; i++)
        data[i] = -1;

    printf("\nBEFORE TRANSMISSION\n");
    sender(data, values, count, parity);

    printf("\nAFTER TRANSMISSION\n");
    receiver(data, count);
}
int hamming_rule(int bits)
{
    int parity = 0, flag = 0;
    while (flag != 1)
    {
        if (bits + parity + 1 <= pow(2, parity))
            flag = 1;
        else
            parity++;
    }
    return (parity);
}
void display(int *data, int count)
{
    for (i = 1; i < count; i++)
        printf(" %d", data[i]);
}
void sender(int *data, int values[], int count, int parity)
{
    int condition[4][4] = {{3, 5, 7, 9}, {3, 6, 7, 10}, {5, 6, 7, -1}, {9, 10, 11, -1}};
    i = 1, j = 0, k = 0;
    while (i <= count) // 7
    {
        if (i == pow(2, k))
        {
            k++;
            i++;
        }
        else
        {
            data[i] = values[j];
            j++;
            i++;
        }
    }
    int place = 0, temp = 0;
    k = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            int temp = condition[i][j];
            if (data[temp] == 1)
                place++;
        }
        if (place % 2 == 0)
        {
            temp = pow(2, k);
            data[temp] = 0;
            k++;
            place = 0;
        }
        else
        {
            temp = pow(2, k);
            data[temp] = 1;
            k++;
            place = 0;
        }
    }
    display(data, count);
}
void receiver(int *data, int count)
{
    // int condition[4][6] = {{1, 3, 5, 7, 9, 11}, {2, 3, 6, 7, 10, -1},{4, 5, 6, 7, -1, -1}, {8, 9, 10, 11, -1, -1}};
    int condition[4][4] = {{3, 5, 7, 9}, {3, 6, 7, 10}, {5, 6, 7, -1}, {9, 10, 11, -1}};

    int flag = 0, place = 0;
    i = 1, j = 0, k = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            int temp = condition[i][j];
            if (data[temp] == 1)
                place++;
        }
        int a = pow(2, k);
        if (place % 2 == data[a])
        {
            k++;
            place = 0;
        }
        else
        {
            printf("\nerror in place:%d", pow(2, k));
            k++;
            flag = 1;
            place = 0;
        }
    }
    if (flag != 1)
        printf("\nNO ERROR\n");
    else
        printf("\nERROR IN DATA TRANSMISSION\n");
}