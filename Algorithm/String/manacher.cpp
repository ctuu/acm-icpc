#include <array>
#include <cctype>
#include <iostream>
#include <vector>
using namespace std;
const char R = 0;
const int N = 1e5 + 7;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    string ns(1, R);
    for (auto i : s)
        ns = ns + (char)i + R;
    int si = ns.size();
    int mx = 0, id = 0;
    array<int, N> p;
    p.fill(0);
    for (int i = 0; i < si; ++i)
    {
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        while (i - p[i] >= 0 && ns[i + p[i]] == ns[i - p[i]])
            p[i]++;
        if (i + p[i] > mx)
        {
            mx = i + p[i];
            id = i;
        }
    }
    mx = 0;
    for (int i = 0; i < si; ++i)
        mx = max(mx, p[i] - 1);
    cout << mx << endl;
    return 0;
}