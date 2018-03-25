#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int N = 10005;
array<pair<double, int>, N> ar;
array<int, N> cnt;
bool cmp(pair<double, int> &a, pair<double, int> &b)
{
    if (a.first == b.first)
    {
        if (cnt[a.second] == cnt[b.second])
            return a.second < b.second;
        return cnt[a.second] > cnt[b.second];
    }
    return a.first > b.first;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, d;
    double p;
    cin >> n;
    for (int i = 0; i < N; ++i)
        ar[i] = make_pair(0.0, i);
    cnt.fill(0);
    for (int i = 0; i < n; ++i)
    {
        cin >> k;
        set<int> gt;
        while (k--)
        {
            cin >> d >> p;
            d--;
            if (!gt.count(d))
            {
                gt.insert(d);
                ar[d].first += p;
                ar[i].first -= p;
                cnt[i]++;
            }
        }
    }
    sort(ar.begin(), ar.begin() + n, cmp);
    for (int i = 0; i < n; ++i)
        cout << ar[i].second + 1 << " " << fixed << setprecision(2) << ar[i].first / 100 << endl;
    return 0;
}