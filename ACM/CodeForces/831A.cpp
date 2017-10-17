#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    array<int, 102> ar;
    int j = -1, k = -1, l = -1;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> ar[i];
    for (int i = 1; i < n; ++i)
        if (ar[i] <= ar[i - 1])
        {
            j=i-1;
            break;
        }
    for (int i = 1; i < n; ++i)
        if (ar[i] > ar[i - 1])
        {
            i = j;
            break;
        }
    if (!ua)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}