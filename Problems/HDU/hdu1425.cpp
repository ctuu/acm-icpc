#include <algorithm>
#include <cstdio>
using namespace std;
#define N 1000007

int a[N];
int main(void)
{
    int n, m;
    while (~scanf("%d %d", &n, &m))
    {
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        sort(a, a + n);
        for (int i = n - 1; i >= n - m; --i)
        {
            if (i < n - 1)
                printf(" ");
            printf("%d", a[i]);
        }
        printf("\n");
    }
    return 0;
}