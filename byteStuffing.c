#include <stdio.h>
int bytestuff(char frame[], char msg[], int n);
int bytedestuff(char data[], char frame[], int n);
void printval(char data[], int count);
int main()
{
    int n;
    printf("enter no of characters:");
    scanf("%d", &n);
    char msg[n], frame[40], data[n];

    printf("\nenter msg\n");
    scanf("%s", msg);

    int ret = bytestuff(frame, msg, n);
    printval(frame, ret);

    int ret2 = bytedestuff(data, frame, ret);
    printval(data, ret2);
}
int bytestuff(char frame[], char msg[], int n)
{
    int j = 1, i;
    frame[0] = 'f';
    for (i = 0; i < n; i++)
    {
        if (msg[i] == 'f' || msg[i] == 'e')
        {
            frame[j] = 'e';
            j++;
            frame[j] = msg[i];
            j++;
        }
        else
        {
            frame[j] = msg[i];
            j++;
        }
    }
    frame[j] = 'f';
    return j + 1;
}
int bytedestuff(char data[], char frame[], int n)
{
    int i = 0, j = 0;

    for (i = 0; i < n; i++)
        data[i] = '@';

    for (i = 1; i < n - 1; i++)
    {
        if (frame[i] == 'e' && (frame[i + 1] == 'e' || frame[i + 1] == 'f'))
        {
            i++;
            data[j] = frame[i];
            j++;
        }
        else
        {
            data[j] = frame[i];
            j++;
        }
    }
    return j;
}
void printval(char data[], int count)
{
    int i;
    for (i = 0; i < count; i++)
        printf("%c", data[i]);
    printf("\n");
}