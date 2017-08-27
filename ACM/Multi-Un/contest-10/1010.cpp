#include <iostream>
#include <algorithm>
#include <array>
#include <set>
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
        multiset<node> ar;
        for (int i = 0; i < n; ++i)
            cin >> va[i].first >> va[i].second;
        sort(va.begin(), va.begin() + n, [](pair<int, int> a, pair<int, int> b) {
            if (a.first != b.first)
                return a.first < b.first;
            else
                return a.second < b.second;
        });
        long long ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int &b = va[i].first;
            int &e = va[i].second;
            auto k = ar.upper_bound(node(b, b));
            if (k == ar.begin())
            {
                ans += e - b;
                ar.insert(node(b,e));
            }
            else
            {
                --k;
                ans += e - k->end;
                int temp = k->beg;
                ar.erase(k);
                ar.insert(node(temp, e));
            }
        }
        cout << ar.size() << " " << ans << endl;
    }
    return 0;
}
