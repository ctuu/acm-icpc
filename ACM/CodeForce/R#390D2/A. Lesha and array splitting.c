#include <stdio.h>
int main(void)
{
    _Bool flag = 0;
    int num[150];
    int ct[300];
    int sum = 0;
    int n, i, k;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &num[i]);
    for (k = 0, i = 0; i < n; i++, k += 2)
    {
        sum = 0;
        if (num[i] != 0)
        {
            ct[k] = i;
            ct[k + 1] = i;
        }
        else if (num[i] == 0 && i < n && i == 0)
        {
            ct[k] = i;
                while (num[i] == 0 && i < n)
                    i++;
            if (i == n)
            {
                flag = 1;
                break;
            }
            ct[k + 1] = i;
        }
        else if (num[i] == 0 && i < n)
        {
            k -= 2;
            ct[k + 1] = i;
        }
    }
    if (flag == 1)
        printf("NO");
    else
    {
        printf("YES\n");
        printf("%d\n", k / 2);
        for (i = 0; i < k; i += 2)
        {
            printf("%d %d\n", ct[i] + 1, ct[i + 1] + 1);
        }
    }
    return 0;
}