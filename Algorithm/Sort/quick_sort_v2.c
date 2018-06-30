#include <stdio.h>
#define N 7
int a[N] = {4, 0, 3, 4, 1, 2, 4};
void q_swap(int *l, int *r)
{
    int tmp = *l;
    *l = *r;
    *r = tmp;
}

void q_sort(int *l, int *r)
{
    int *s = l, *m = --r;
    if (l > --r)  return;
    while (l < r)
    {
        while (*l < *m && l < r)  ++l;
        while (*r >= *m && l < r) --r;
        q_swap(l, r);
    }
    if (*l > *m) q_swap(l, m);
    q_sort(s, l + 1);
    q_sort(r + 1, m + 1);
}   

int main(void)
{
    for (int i = 0; i < N; ++i)
        printf("%d ", a[i]);
    printf("\nAFTER\n");
    q_sort(a, a + N);
    printf("\n");
    for (int i = 0; i < N; ++i)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}