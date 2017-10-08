#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <iomanip>
using namespace std;
array<vector<int>, 100005> ar;
vector<long long> ans;
double an = 0;
void dfs(int l, int c, long long len, double gl);
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    long long ct = ar[1].size();
    for (auto i: ar[1])
    {
    dfs(1, i, 1, 1.0 / ct);
    }
    // long long ct = ans.size();
    if (ct)
    {
        // for (auto i : ans)
        //     an += (double)i / ct;
        cout << setprecision(15) << fixed << an << endl;
    }
    else
        cout << "0.000000000000000" << endl;
    return 0;
}

void dfs(int l, int c, long long len, double gl)
{
    bool iso = 1;
    for (auto i : ar[c])
    {
        if (i != l)
        {
            dfs(c, i, len + 1, gl / (ar[c].size() - 1));
            iso = 0;
        }
    }
    if (iso)
    {
        an += len * gl;
        // cout << l << " " << c << " " << len << " " << gl << endl;
        return;
    }
}