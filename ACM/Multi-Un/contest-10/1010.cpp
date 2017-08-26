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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<set<int>> ar;
        array<pair<int, int>, 100003> va;
        // ar.resize(100000);
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
            bool isa = 0;
            if (!ar.size())
            {
                set<int> t;
                t.insert(b);
                t.insert(e);
                ar.push_back(t);
            }
            else
            {
                sort(ar.begin(), ar.end(), [](set<int> a, set<int> b) {
                    return *a.rbegin() > *b.rbegin();
                });
                for (auto &i : ar)
                {
                    if (*i.rbegin() <= b)
                    {
                        i.insert(e);
                        isa = 1;
                        break;
                    }
                }
                if (!isa)
                {
                    set<int> t;
                    t.insert(b);
                    t.insert(e);
                    ar.push_back(t);
                }
            }
        }
        int ans = 0;
        for (auto i : ar)
            ans += *i.rbegin() - *i.begin();
        cout << ar.size() << " " << ans << endl;
    }
    return 0;
}