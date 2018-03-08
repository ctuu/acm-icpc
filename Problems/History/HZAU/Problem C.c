#include <stdio.h>
#define PI 3.14159265358
int main(void)
{
    double l;
    char formal[100];
    int n, ct, k;
    while (~scanf("%lf%d", &l, &n))
    {
        if (l == 0)
        {
            printf("0\n");
            continue;
        }
        sprintf(formal, "%.*f\n", 7, PI * l * l);

        for (ct = 0; formal[ct] != '.'; ct++)
            printf("%c", formal[ct]);
        if (n == 0)
        {
            printf("\n");
            continue;
        }
        printf(".");
        for (k = ++ct; k < ct + n; k++)
            printf("%c", formal[k]);
        printf("\n");
    }
    return 0;
}