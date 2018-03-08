#include <bits/stdc++.h>
using namespace std;
int prim[100002] = {0};
void mpn();
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    mpn();
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i < n - 1; ++i)
         if (!prim[i] && !prim[i + 2])
             ++sum;
    cout << sum;
    return 0;
}
void mpn()
{
    prim[0] = prim[1] = 1;
    for (int i = 2; i < 5001; ++i)
    {
        if (prim[i])
            continue;
        for (int j = 2 * i; j < 100001; j += i)
            prim[j] = 1;
    }
}

