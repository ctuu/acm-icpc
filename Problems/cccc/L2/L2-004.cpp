#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
vector<int> tree[1003];
array<int, 1003> fa, v, lr;
bool search(int b, int e, bool fl)
{
    if (b >= e - 1)
        return 0;
    int r = b, c1 = b + 1, c2 = e;
    for (int i = b + 1; i < e; ++i)
        if (fl)
        {
            if (v[i] >= v[r])
            { 
                c2 = i;
                break;
            }
            if (lr[r] == 1 && v[i] < fa[r])
                return 1;
            if (lr[r] == 0 && v[i] >= fa[r])
                return 1;
        }
        else
        {
            if (v[i] < v[r])
            {
                c2 = i;
                break;
            }
            if (lr[r] == 1 && v[i] >= fa[r])
                return 1;
            if (lr[r] == 0 && v[i] < fa[r])
                return 1;
        }
    fa[c1] = fa[c2] = v[r];
    lr[c1] = 0;
    lr[c2] = 1;
    if(c1 != c2)
        tree[r].push_back(c1);
    if (c2 <= e - 1)
        tree[r].push_back(c2);
    // cout << fl << "!! " << r << " " << c1 << " " << c2 << endl;
    if (!search(c1, c2, fl) && !search(c2, e, fl))
        return 0;
    return 1;
}
void dfs(int c)
{
    for (auto i : tree[c])
        dfs(i);
    cout << v[c] << " ";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    bool fl = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        fa[i] = i;
    }
    lr[0] = -1;
    if (search(0, n, 1))
    {
        fa.fill(1003);
        for(int i = 0; i < 1003; ++i)
            tree[i].clear();
        if (search(0, n, 0))
            fl = 1;
    }
    if (!fl)
    {
        cout << "YES" << endl;
        for (auto i : tree[0])
            dfs(i);
        cout << v[0] << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}