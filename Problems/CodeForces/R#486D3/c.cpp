#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int OF = 1e4 + 7;
const int N = 2e5 + OF + 7;
// array<map<int, int>, N> ar;
map<int, map<int, int>> ar;
array<int, N> tr;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> m;
        int sm = 0;
        for (int j = 0; j < m; ++j)
        {
            cin >> tr[j];
            sm += tr[j];
        }
        for (int j = 0; j < m; ++j)
            ar[sm - tr[j] + OF][i + 1] = j + 1;
    }

    for (auto x : ar)
        if (x.second.size() > 1)
        {
            cout << "YES" << endl;
            int ct = 0;
            for (auto &i : x.second)
            {
                ct++;
                cout << i.first << " " << i.second << endl;
                if (ct >= 2)
                    return 0;
            }
        }
    cout << "NO" << endl;
    return 0;
}