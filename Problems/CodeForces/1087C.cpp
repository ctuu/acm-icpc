#include <cmath>
#include <array>
#include <vector>
#include <iostream>
using namespace std;
const int N = 1000 + 7;
using PII = pair<int, int>;
array<array<bool, N>, N> ar;
vector<PII> vt;
void calc(PII a, PII b, PII c)
{
    vt.clear();
    for (auto &i : ar)
        i.fill(0);
    ar[a.first][a.second] = 1;
    ar[b.first][b.second] = 1;
    ar[c.first][c.second] = 1;
    int tx = a.first, fl = a.first > b.first ? 1 : -1;
    while (tx != b.first)
    {
        ar[tx][a.second] = 1;
        tx -= fl;
    }
    tx = c.first, fl = c.first > b.first ? 1 : -1;
    while (tx != b.first)
    {
        ar[tx][c.second] = 1;
        tx -= fl;
    }
    int mi = min(b.second, min(a.second, c.second)), ma = max(b.second, max(a.second, c.second));
    while (mi <= ma)
        ar[b.first][mi++] = 1;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (ar[i][j])
                vt.push_back({i, j});
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    PII a, b, c;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> c.first >> c.second;
    vector<PII> vc;
    calc(a, b, c);
    vc = vt;
    calc(c, a, b);
    if (vt.size() < vc.size())
        vc = vt;
    calc(b, c, a);
    if (vt.size() < vc.size())
        vc = vt;
    cout << vc.size() << '\n';
    for (auto i : vc)
        cout << i.first << ' ' << i.second << '\n';
    return 0;
}