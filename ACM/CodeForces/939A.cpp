#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    array<int, 5003> ar;
    for (int i = 1; i <= n; ++i)
        cin >> ar[i];
    bool fl = 0;
    for (int i = 1; i <= n; ++i)
        if (ar[ar[ar[i]]] == i)
        {
            fl = 1;
            break;
        }
    if (fl)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}