#include <stdio.h>
int main(void)
{
    int num[1000];
    int count[1000] = {1};
    int n, i, k, s;
    int max = 0;
    while (scanf("%d", &n) != EOF)
    {
        for (max = 0, s = 0; s < 1000; s++)
            count[s] = 1;
        for (i = 0; i < n; i++)
            scanf("%d", &num[i]);
        num[n] = 0;
        for (k = 0, i = 0; i < n; i++)
        {
            for (; num[i] < num[i + 1]; i++)
                count[k]++;
            k++;
        }
        for (; k > -1; k--)
            max = (max > count[k]) ? max : count[k];
        printf("%d\n", max);
    }
    return 0;
}