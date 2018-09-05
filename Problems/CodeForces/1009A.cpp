#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a, b;
    a.resize(n);
    b.resize(m);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    int ans = 0, i, j;
    for (i = 0; i < n && j < m; ++i)
        if (a[i] <= b[j])
        {
            ans++;
            ++j;
        }
    cout << ans << endl;
    return 0;
}
