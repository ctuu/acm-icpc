#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a, x;
    a.resize(n);
    x.resize(n);
    for (auto &i : a)
        cin >> i;
    x[0] = a[0];
    for (int i = 1; i < n; ++i)
        x[i] = a[i] - a[i - 1];
    vector<int> ans;
    for (int i = 1; i <= n; ++i)
    {
        bool fl = 1;
        for (int j = 0; j < n; j++)
            if (x[j % i] != x[j])
            {
                fl = 0;
                break;
            }
        if (fl)
            ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << ' ';
    return 0;
}
