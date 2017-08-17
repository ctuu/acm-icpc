#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#define MN 10000005
using namespace std;
array<int, MN> a;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    a[1] = 1;
    int i = 1, j = 0;
    while (j++ < MN - 1)
    {
        if (a[i] == 1 && a[j] == 1)
            a[j + 1] = 2;
        else if (a[i] == 1 && a[j] == 2)
            a[j + 1] = 1;
        else if (a[i] == 2 && a[j] == 2)
        {
            a[j + 1] = 2;
            a[j + 2] = 1;
            ++j;
        }
        else if (a[i] == 2 && a[j] == 1)
        {
            a[j + 1] = 1;
            a[j + 2] = 2;
            ++j;
        }
        ++i;
    }
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << a[n] << endl;
    }
    return 0;
}