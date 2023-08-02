#include <stdio.h>
#include <stdlib.h>
void bitstuff(int data[], int n, int frame[], int size);
void bitdestuff(int frame[], int size, int n);
void printval(int a[], int count);
int main()
{
        int i, n;
        printf("\nenter no of data bits:");
        scanf("%d", &n);

        int size = n + 16 + (n / 8);
        int frame[size];
        int data[n];

        printf("\nenter data\n");
        for (i = 0; i < n; i++)
                scanf("%d", &data[i]);
        bitstuff(data, n, frame, size);

        bitdestuff(frame, size, n);
        return 0;
}
void bitstuff(int data[], int n, int frame[], int size)
{
        int flag[] = {0, 1, 1, 1, 1, 1, 1, 0};
        int i;
        for (i = 0; i < size; i++)
                frame[i] = -1;

        for (i = 0; i < 8; i++)
                frame[i] = flag[i];

        int count = 0, j = 8;
        i = 0;
        while (i < n)
        {
                if (data[i] == 1)
                {
                        count++;
                        if (count == 6)
                        {
                                frame[j] = 0;
                                j++;
                                frame[j] = data[i];
                                j++;
                        }
                        else
                        {
                                frame[j] = data[i];
                                j++;
                        }
                }
                else
                {
                        frame[j] = data[i];
                        j++;
                }
                i++;
        }

        int retval = j;
        i = 0;
        while (j < j + 8 && i < 8)
        {
                frame[j] = flag[i];
                i++;
                j++;
        }
        printf("stuffed data\n");
        printval(frame, size);
}
void bitdestuff(int frame[], int size, int n)
{
        printf("\nbit destuffing\n");

        int i, j = 0, k = 1;
        int count = size - 16;
        count = count - (count / 8);
        int msg[count];
        for (i = 0; i < count; i++)
                msg[i] = -1;

        for (i = 8; i < size - 7; i++)
        {

                if (frame[i] == 1 && k < 6)
                {
                        msg[j] = frame[i];
                        j++;
                        k++;
                }
                else if (k == 6 && frame[i] == 0)
                {
                        i++;
                        msg[j] = frame[i];
                        j++;
                        k = 0;
                }
                else
                {
                        msg[j] = frame[i];
                        j++;
                }
        }
        printf("destuffed data\n");
        printval(msg, count);
}
void printval(int a[], int count)
{
        int i;
        for (i = 0; i < count; i++)
                printf("%d ", a[i]);
}