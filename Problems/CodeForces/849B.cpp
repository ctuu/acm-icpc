#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
array<int, 1003> ar;
int n;
bool che(double k)
{
    int p = -1;
    for (int i = 2; i <= n; ++i)
    {
        if ((i - 1) * k == ar[i] - ar[1])
            continue;
        if (p == -1)
            p = i;
        else if ((i - p) * k != ar[i] - ar[p])
            return 0;
    }
    return p != -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> ar[i];
    if (che(ar[2] - ar[1]) || che((ar[3] - ar[1]) / 2.0) || che(ar[3] - ar[2]))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}