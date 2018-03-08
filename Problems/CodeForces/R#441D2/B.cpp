#include <iostream>
#include <algorithm>
#include <array>
#include <set>
#include <map>
#include <vector>
#define MAM 100002
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, m, tmp;
    cin >> n >> k >> m;
    array<int, MAM> var;
    var.fill(0);
    map<int, int> mar;
    set<int> ar;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        mar[tmp]++;
        ar.insert(tmp);
    }
    for (auto i : ar)
        var[i % m] += mar[i];
    int tg;
    bool fl = 0;
    for (int i = 0; i <= m; ++i)
        if (var[i] >= k)
        {
            fl = 1;
            tg = i;
            break;
        }
    if (!fl)
    {
        cout << "No";
        return 0;
    }
    cout << "Yes" << endl;
    for (auto i : ar)
    {
        if (k <= 0)
            break;
        if (i % m == tg)
            while (mar[i]-- && k--)
                cout << i << " ";
    }
    return 0;
}