#include <stdio.h>
#define N 1000007

int a[N];

void q_swap(int *l, int *r)
{
    int tmp = *l;
    *l = *r;
    *r = tmp;
}

void q_sort(int *l, int *r)
{
    int *s = l, *m = --r;
    r--;
    if (l > r)
        return;
    while (l < r)
    {
        while (*l < *m && l < r)
            ++l;
        while (*r >= *m && l < r)
            --r;
        q_swap(l, r);
    }
    if (*l > *m)
        q_swap(l, m);
    q_sort(s, l + 1);
    q_sort(r + 1, m + 1);
}

int main(void)
{
    int n, m;
    while (~scanf("%d %d", &n, &m))
    {
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        q_sort(a, a + n);
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