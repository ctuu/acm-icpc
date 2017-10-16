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
    int n, m, a, b, mb = 0;
    cin >> n >> m;
    array<int, 103> ar;
    set<int> ex;
    ar.fill(-1);
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        ar[a] = b;
        ex.insert(a);
    }
    bool ans = 0;
    int mfl = -1;
    for (int i = 1; i <= 101; ++i)
    {
        int fl = 0, le = 1;
        for (int j = 1; j <= 101; ++j)
        {
            if (ar[j] == le)
                fl++;
            if (j % i == 0)
                le++;
        }
        if (n % i == 0)
            --le;
        if (fl == m)
        {
            array<int, 102> tmp;
            for (int j = 1, k = 1; j <= 101; ++j)
            {
                tmp[j] = k;
                if (j % i == 0)
                    ++k;
            }
            int ct = 0;
            for (auto i : ex)
                if (tmp[i] == ar[i])
                    ++ct;
            if (ct == m)
            {
                // cout << "! " << i << endl;
                if (ans && mfl != (n + i - 1) / i)
                {
                    mfl = -1;
                    break;
                }
                ans = 1;
                mfl = (n + i - 1) / i;
            }
        }
    }
    cout << mfl;
    return 0;
}