#include <stdio.h>

int main(void)
{
    int max, T, t, k;
    _Bool nu[26] = {0};
    char ch;
    scanf("%d", &T);
    while (getchar() != '\n')
        continue;
    for (t = 0; t < T;)
    {
        max = 0;
        _Bool nu[26] = {0};
        while ((ch = getchar()) != '\n')
            nu[ch - 97] = 1;
        printf("Case #%d: ", ++t);
        for (k = 0; k < 26;)
            if (nu[k++] == 1)
                max++;
        printf("%d\n", max);
    }
    return 0;
}