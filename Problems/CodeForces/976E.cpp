#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
using LL = long long;
struct Nd
{
    LL hp, dg, sb;
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    LL n, a, b;
    LL ans = 0;
    cin >> n >> a >> b;
    vector<Nd> vc;
    for (int i = 0; i < n; ++i)
    {
        Nd tmp;
        cin >> tmp.hp >> tmp.dg;
        tmp.sb = max(0LL, tmp.hp - tmp.dg);
        vc.push_back(tmp);
        ans += tmp.dg;
    }

    sort(vc.begin(), vc.end(), [](Nd x, Nd y) {
        return x.sb > y.sb;
    });

    b = min(b, n);
    for (int i = 0; i < b; ++i)
        ans += vc[i].sb;
    LL ma = 0;
    for (int i = 0; b && i < n; ++i)
        ma = max(ma, (vc[i].hp << a) - vc[i].dg - vc[i < b ? i : b - 1].sb);

    cout << ans + ma << endl;
    return 0;
}
