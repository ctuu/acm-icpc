#include <array>
#include <iostream>
using namespace std;
array<array<char, 103>, 5> ar;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (auto &i : ar)
        i.fill('.');
    int n, k;
    cin >> n >> k;
    if (k % 2 == 0)
    {
        int t = k / 2 + 2;
        for (int j = 2; j < t; ++j)
            ar[2][j] = ar[3][j] = '#';
    }
    else if (n % 2 == 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    else
    {
        ar[2][(n + 1) / 2] = '#';
        k--;
        for (int j = 2; k && j < (n + 1) / 2; ++j)
        {
            ar[2][j] = ar[2][n - j + 1] = '#';
            k -= 2;
        }
        for (int j = 2; k && j < (n + 1) / 2; ++j)
        {
            ar[3][j] = ar[3][n - j + 1] = '#';
            k -= 2;
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= 4; ++i, cout << endl)
        for (int j = 1; j <= n; ++j)
            cout << ar[i][j];
    return 0;
}