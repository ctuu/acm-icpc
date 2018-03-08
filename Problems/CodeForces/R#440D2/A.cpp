#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    array<bool, 11> a, b;
    a.fill(0);
    b.fill(0);
    int n, m, tmp;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        a[tmp] = 1;
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> tmp;
        b[tmp] = 1;
    }
    int sum = 100;
    for (int i = 1; i < 10; ++i)
        if (a[i] && b[i])
        {
            cout << i;
            return 0;
        }
    for (int i = 1; i < 10; ++i)
        for (int j = 1; j < 10; ++j)
            if (a[i] && b[j])
                sum = min(sum, min(j * 10 + i, i * 10 + j));
    cout << sum;
    return 0;
}