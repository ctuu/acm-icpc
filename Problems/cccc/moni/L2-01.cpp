#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
const int N = 100005;
array<vector<int>, N> ar;
array<double, N> gl, bs;
int n;
double z, r, sum = 0;
void dfs(int c)
{
    sum += bs[c] * gl[c];
    for (auto i : ar[c])
    {
        gl[i] = gl[c] * (1 - r);
        dfs(i);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> z >> r;
    r /= 100;
    gl[0] = z;
    bs.fill(0.0);
    for (int i = 0; i < n; ++i)
    {
        int k, t;
        cin >> k;
        if (k == 0)
        {
            cin >> bs[i];
            continue;
        }
        for (int j = 0; j < k; ++j)
        {
            cin >> t;
            ar[i].push_back(t);
        }
    }
    dfs(0);
    cout << (int)sum << endl;
    return 0;
}