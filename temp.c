#include <stdio.h>
int score(void);
int main(void)
{
    printf("%d", score());
    return 0;
}
int score(void)
{
    int i;
    if (~scanf("%d", &i))
    {
        if (i < 60)
            return score() + 1;
        else
            return score();
    }
    else
        return 0;
}