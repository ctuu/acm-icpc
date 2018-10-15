#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    if (m >= n)
    {
        cout << n << endl;
        return 0;
    }
    int ans = 0;
    vector<int> a;
    a.resize(n);
    for (auto &i : a)
        cin >> i;
    int cp = 0;
    for (auto i = a.rbegin(); i < a.rend(); ++i)
    {
        if (cp + *i > k)
        {
            m--;
            cp = 0;
        }
        if (!m)
            break;
        cp += *i;
        ans++;
    }
    cout << ans << endl;
    return 0;
}