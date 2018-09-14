#include <iostream>
#include <array>
using namespace std;
const int N = 1000 + 7;

array<int, N> p;
array<bool, N> ct;

int dfs(int x)
{
    if (ct[x])
        return x;
    ct[x] = 1;
    return dfs(p[x] - 1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    for (int i = 0; i < n; ++i)
    {
        ct.fill(0);
        cout << dfs(i) + 1 << " ";
    }
    return 0;
}