#include <iostream>
#include <algorithm>
#include <array>
#include <set>
#include <vector>
using namespace std;
array<pair<int, int>, 100003> va;
struct node
{
    int beg, end;
    node() = default;
    node(int a, int b)
    {
        this->beg = a;
        this->end = b;
    }
    friend bool operator<(const node &a, const node &b)
    {
        if (a.beg != b.beg)
            return a.beg < b.beg;
        return a.end < b.end;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        set<node> ar;
        // array<pair<int, int>, 100003> va;
        for (int i = 0; i < n; ++i)
            cin >> va[i].first >> va[i].second;
        sort(va.begin(), va.begin() + n, [](pair<int, int> a, pair<int, int> b) {
            if (a.first != b.first)
                return a.first < b.first;
            else
                return a.second < b.second;
        });

        for (int i = 0; i < n; ++i)
        {
            int &b = va[i].first;
            int &e = va[i].second;
            if (!ar.size())
                ar.insert(node(b, e));
            else
            {
                auto k = upper_bound(ar.begin(), ar.end(), node(b, e), [](node a, node b) {
                    return a.beg < b.end;
                });
                --k;
                // cout << i << " ! " << b << " " << k->end << endl;
                if (k->end <= b)
                {
                    ar.insert(node(k->beg, e));
                    ar.erase(k);
                    continue;
                }
                else
                    ar.insert(node(b, e));
            }
        }
        int ans = 0;
        for (auto i : ar)
            ans += i.end - i.beg;
        cout << ar.size() << " " << ans << endl;
    }
    return 0;
}