#include <stdio.h>
void time(int t);
int main(void)
{
    int h, m;
    scanf("%d%d", &h, &m);
    time(h);
    if (m == 0)
        printf(" o'clock");
    else
    {
        printf(" ");
        time(m);
    }
    return 0;
}

void time(int t)
{
    switch (t)
    {
    case 0:
        printf("zero");
        return;
    case 1:
        printf("one");
        return;
    case 2:
        printf("two");
        return;
    case 3:
        printf("three");
        return;
    case 4:
        printf("four");
        return;
    case 5:
        printf("five");
        return;
    case 6:
        printf("six");
        return;
    case 7:
        printf("seven");
        return;
    case 8:
        printf("eight");
        return;
    case 9:
        printf("nine");
        return;
    case 10:
        printf("ten");
        return;
    case 11:
        printf("eleven");
        return;
    case 12:
        printf("twelve");
        return;
    case 13:
        printf("thirteen");
        return;
    case 14:
        printf("fourteen");
        return;
    case 15:
        printf("fifteen");
        return;
    case 16:
        printf("sixteen");
        return;
    case 17:
        printf("seventeen");
        return;
    case 18:
        printf("eighteen");
        return;
    case 19:
        printf("nineteen");
        return;
    default:
        break;
    }

    switch (t / 10)
    {
    case 2:
        printf("twenty");
        t %= 20;
        break;
    case 3:
        printf("thirty");
        t %= 30;
        break;
    case 4:
        printf("forty");
        t %= 40;
        break;
    case 5:
        printf("fifty");
        t %= 50;
        break;
    }
    switch (t)
    {
    case 1:
        printf(" one");
        return;
    case 2:
        printf(" two");
        return;
    case 3:
        printf(" three");
        return;
    case 4:
        printf(" four");
        return;
    case 5:
        printf(" five");
        return;
    case 6:
        printf(" six");
        return;
    case 7:
        printf(" seven");
        return;
    case 8:
        printf(" eight");
        return;
    case 9:
        printf(" nine");
        return;
    }
}