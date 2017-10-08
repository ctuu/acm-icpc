#include <iostream>
#include <algorithm>
#include <array>
#include <set>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    array<set<int>, 102> ar;
    string s;
    cin >> s;
    bool fg = 0;
    for (auto i : s)
    {
        bool flag = 0;
        for (int j = 0; j < k; ++j)
            if (!ar[j].count(i))
            {
                ar[j].insert(i);
                flag = 1;
                break;
            }
        if (!flag)
            fg = 1;
    }
    if (fg)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}