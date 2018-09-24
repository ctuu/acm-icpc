#include <iostream>
#include <array>
#include <string>
const int N = 107;
using namespace std;

array<array<int, N>, N> a;
int n;
bool find(int num, int l)
{
    if (l >= n)
        return 1;
    bool res = 0;
    for (int i = l; i < n; ++i)
        if (a[l][i] == num)
            res = res | find(num, i + 1);
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (auto &i : a)
        i.fill(0);

    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i)
    {
        int c = s[i] - '0';
        a[i][i] = c;
    }
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            a[i][j] = a[i][j - 1] + a[j][j];
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < n; ++j)
    //         cout << a[i][j] << ' ';
    //     cout << endl;
    // }
    for (int i = 0; i < n - 1; ++i)
        if (find(a[0][i], i + 1))
        {
            cout << "YES" << endl;
            return 0;
        }
    cout << "NO" << endl;
    return 0;
}