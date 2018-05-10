#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
const int N = 5e5 + 7;
const int INF = 0x3f3f3f3f;
array<int, N> d, ty;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b, T = 1;
    while (cin >> n)
    {
        ty.fill(-1);
        d.fill(INF);
        d[0] = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            ty[a] = b;
        }

        for (int i = 1; i <= n; ++i)
        {
            int &c = ty[i];
            int tg = lower_bound(d.begin(), d.end(), c) - d.begin();
            d[tg] = c;
        }
        int si = 1;
        while (d[si + 1] != INF)
            si++;
        cout << "Case " << T++ << ":" << endl;
        cout << "My king, at most " << si;
        si > 1 ? cout << " roads" : cout << " road";
        cout << " can be built." << endl;
        cout << endl;
    }
    return 0;
}