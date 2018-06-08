#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
using LL = long long;

const int PN = 33;
const int N = 2e5 + 7;
array<int, PN> p;
array<LL, N> a;
array<LL, 4> ans, tns;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    p[0] = 1;
    set<LL> hs;
    for (int i = 1; i < PN; ++i)
        p[i] = p[i - 1] * 2;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        hs.insert(a[i]);
    }
    sort(a.begin(), a.begin() + n);
    int ct = 1;
    ans[0] = a[0];

    for (int i = 0; i < n; ++i)
    {
        if (ct == 3)
            break;
        for (int j = 0; j < PN-1; ++j)
        {
            LL tmp = a[i];
            tns[0] = tmp;
            int tct = 1;
            for (int k = 1; k < 3; ++k)
            {
                tmp += p[j];
                if (!hs.count(tmp))
                    break;
                tct++;
                tns[k] = tmp;
            }
            if (tct > ct)
            {
                ct = tct;
                for (int i = 0; i < 3; ++i)
                    ans[i] = tns[i];
            }
        }
    }

    cout << ct << endl;
    for (int i = 0; i < ct; ++i)
        cout << ans[i] << " ";

    return 0;
}
