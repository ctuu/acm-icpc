#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;
const int N = 100 + 7;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    array<int, N> a;
    a.fill(0);
    array<vector<int>, N> ars;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int c;
        cin >> c;
        a[c]++;
    }
    for (int i = 1; i < N; ++i)
    {
        for (int j = 1; j < N; ++j)
        {
            if (a[i] / j == 0)
                break;
            ars[j].push_back(a[i] / j);
        }
    }
    for (int i = N - 1; i > 0; --i)
    {
        int c = 0;
        for (auto j : ars[i])
            c += j;
        if (c >= n)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}