#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
array<int, 1004> po;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    array<int, 1004> po, me;
    po.fill(INF);
    int n, t;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> t;
        po[t] = i;
        me[i] = t;
    }
    sort(po.begin(), po.end());
    vector<int> as;
    int ct = 0;
    for (auto i : po)
    {
        if (i == INF)
            break;
        ct++;
        as.push_back(me[i]);
    }
    cout << ct << endl;
    for (auto i : as)
        cout << i << " ";
    return 0;
}