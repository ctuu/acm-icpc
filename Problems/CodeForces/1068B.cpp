#include <iostream>
#include <algorithm>
#include <cmath>
#include <array>
using namespace std;
const int N = 2e5 + 7;
array<int, N> pr;
array<bool, N> chk;
void pd(void)
{
    int pos = 0;
    pr.fill(-1);
    chk.fill(1);
    for (int i = 2; i < N; ++i)
    {
        if (chk[i])
            pr[pos++] = i;
        for (int j = 0; j < pos && i * pr[j] < N; ++j)
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
    long long b;
    cin >> b;
    if(chk[b])
    {

    }
    long long ans = 0;
    for (int i = 0; i < N; ++i)
        if (pr[i] > b)
        {
            cout << i << endl;
            return 0;
        }

    return 0;
}