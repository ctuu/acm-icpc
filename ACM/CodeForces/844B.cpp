#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long num[55][55] = {0};
    num[1][0] = 1;
    for (int m = 1; m <= 51; m++)
        for (int n = 1; n <= 51 + 1; n++)
            num[n][m] = num[n - 1][m - 1] + num[n][m - 1];
    array<array<bool, 53>, 53> ar;
    array<int, 53> rb, bb;
    rb.fill(0), bb.fill(0);
    int n, m;
    cin >> n >> m;
    long long sum = -n*m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            cin >> ar[i][j];
            if (ar[i][j])
                rb[i]++;
        }
    for (int j = 0; j < m; ++j)
        for (int i = 0; i < n; ++i)
        {
            if (ar[i][j])
                bb[j]++;
        }
    for (int i = 0; i < n; ++i)
    {
        int tmp = rb[i];
        for (int j = 1; j <= tmp; ++j)
            sum += num[j + 1][tmp];
        tmp = m - rb[i];
        for (int j = 1; j <= tmp; ++j)
            sum += num[j + 1][tmp];
    }
    for (int i = 0; i < m; ++i)
    {
        int tmp = bb[i];
        for (int j = 1; j <= tmp; ++j)
            sum += num[j + 1][tmp];
        tmp = n - bb[i];
        for (int j = 1; j <= tmp; ++j)
            sum += num[j + 1][tmp];
    }
    cout << sum;
    return 0;
}