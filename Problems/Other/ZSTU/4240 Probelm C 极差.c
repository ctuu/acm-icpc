#include <stdio.h>
int main(void)
{
    int T, b, ct;
    int max = 0;
    int min = 100001;
    int num[1000];
    scanf("%d", &T);
    while (T > 0)
    {
        scanf("%d", &b);
        max = 0;
        min = 100001;
        for (ct = 0; ct < b; ct++)
        {
            scanf("%d", &num[ct]);
            max = (max > num[ct]) ? max : num[ct];
            min = (min < num[ct]) ? min : num[ct];
        }
        printf("%d\n", max - min);
        T--;
    }
    return 0;
}