#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char W[10010], T[1000010];
int wlen, tlen, next[10010];
void getNext();
int KMP_count();
int main()
{
    int tcase;
    scanf("%d", &tcase);
    while (tcase--)
    {
        scanf("%s%s", &W, &T);
        wlen = strlen(W);
        tlen = strlen(T);

        printf("%d\n", KMP_count());
    }
    return 0;
}

void getNext()
{
    int j, k;
    j = 0;
    k = -1;
    next[0] = -1;
    while (j < wlen)
    {
        if (k == -1 || W[j] == W[k])
        {
            next[++j] = ++k;
        }
        else
            k = next[k];
    }
}
int KMP_count()
{
    int ans = 0;
    int i, j = 0;
    if (wlen == 1 && tlen == 1)
    {
        if (W[0] == T[0])
            return 1;
        else
            return 0;
    }
    getNext();
    for (i = 0; i < tlen; i++)
    {
        while (j > 0 && T[i] != W[j])
            j = next[j];
        if (W[j] == T[i])
            j++;
        if (j == wlen)
        {
            ans++;
            j = next[j];
        }
    }
    return ans;
}