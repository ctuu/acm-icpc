#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
using LL = long long;

map<LL, int> mp;
array<LL, 103> ar;
bool ans = 0;

void dfs(LL cur, int la)
{
    if (ans || la == 0)
    {
        ans = 1;
        return;
    }
    LL po = cur / 3;
    if (cur % 3 == 0)
    {
        if (mp[po])
        {
            mp[po]--;
            ar[la - 1] = po;
            dfs(po, la - 1);
            mp[po]++;
            if (ans)
                return;
        }
    }
    po = cur * 2;
    if (mp[po])
    {
        mp[po]--;
        ar[la - 1] = po;
        dfs(po, la - 1);
        mp[po]++;
        if (ans)
            return;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<LL> vc;
    vc.resize(n);
    for (auto &i : vc)
    {
        cin >> i;
        mp[i]++;
    }
    for (auto i : vc)
    {
        ar[n - 1] = i;
        dfs(i, n - 1);
        if(ans)
            break;
    }
    for (int i = n - 1; i >= 0; --i)
        cout << ar[i] << " ";
    cout << endl;
    return 0;
}