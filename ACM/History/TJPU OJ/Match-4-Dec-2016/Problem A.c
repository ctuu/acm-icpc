#include <stdio.h>
int main(void)
{
    int T, sum;
    char temp;
    scanf("%d", &T);
    while (getchar() != '\n')
        continue;
    for (; T > 0; T--)
    {
        sum = 0;
        while ((temp = getchar()) != '\n')
        {
            if (temp == 'C')
                sum += 12;
            if (temp == 'O')
                sum += 16;
            if (temp == 'H')
                sum += 1;
        }
        printf("%d\n", sum);
    }
    return 0;
}