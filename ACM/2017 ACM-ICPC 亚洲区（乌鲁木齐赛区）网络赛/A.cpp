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
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        array<set<int>, 55> ar;
        array<set<int>, 55> br;
        set<int> to;
        for (int i = 0; i < n; ++i)
        {
            int a, b;
            cin >> a >> b;
            to.insert(a);
            ar[a].insert(b);
        }
        for (int i = 0; i < m; ++i)
        {
            int a, b;
            cin >> a >> b;
            br[a].insert(b);
        }
        for (auto i: to)
        {
            set<int> in;
            for (auto j: ar[i])
            {
                for (auto k: br[j])
                in.insert(k);
            }
            for (auto j: in)
            cout << i << " " << j <<endl;
        }
        cout << endl;
    }
    return 0;
}