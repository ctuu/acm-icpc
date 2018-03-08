#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    array<int, 103> ar;
    int n, tmp;
    cin >> n;
    if (!(n &1))
    {
        cout << "No";
        return 0;
    }
    for (int i = 0; i < n; ++i)
        cin >> ar[i];
    if (ar[0]&1 && ar[n-1]&1)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}