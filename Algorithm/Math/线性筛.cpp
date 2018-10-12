#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
const int M = 15e6 + 7;

array<int, M> ton;
array<int, M> pr;
array<bool, M> chk;
array<int, N> a;
void pd(void)
{
    int pos = 0;
    pr.fill(-1);
    chk.fill(1);
    for (int i = 2; i < M; ++i)
    {
        if (chk[i])
            pr[pos++] = i;
        for (int j = 0; j < pos && i * pr[j] < M; ++j)
        {
            chk[i * pr[j]] = 0;
            if (i % pr[j] == 0)
                break;
        }
    }
}

int main()
{
    pd();
    for (int i = 0; i < 10; ++i)
        cout << pr[i] << ' ';
    cout << endl;
    return 0;
}