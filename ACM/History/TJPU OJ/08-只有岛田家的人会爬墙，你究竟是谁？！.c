#include <stdio.h>
#define HEIGHT 700000
int main(void)
{
    int a, b, t, day;
    while (scanf("%d", &day) != EOF)
    {
 
        for (a = 0, b = 1, t = 0; day > 0; day--)
        {
            t = b;
            b += a;
            a = t;
            if ( b >= HEIGHT)
            {  
                printf("YES\n");
                break;
            }
        }
            if ( b < HEIGHT )
            printf("%d\n", HEIGHT - b);
    }
    return 0;
}