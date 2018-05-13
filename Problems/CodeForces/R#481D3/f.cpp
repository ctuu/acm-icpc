#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
const int N = 2e5 + 7;
array<int, N> r, j;
array<vector<int>, N> fk;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> r[i];
        j[i] = r[i];
    }
    sort(j.begin() + 1, j.begin() + n + 1);
    for (int i = 0; i < k; ++i)
    {
        int x, y;
        cin >> x >> y;
        fk[x].push_back(y);
        fk[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        int L = 0, R = n;
        while (L < R)
        {
            int M = (L + R + 1) / 2;
            if (j[M] < r[i])
                L = M;
            else
                R = M - 1;
        }
        int ans = L;
        for (auto j : fk[i])
            if (r[j] < r[i])
                ans--;
        cout << ans << " " ;
    }
    return 0;
}