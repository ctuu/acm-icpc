#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, mak = 0;
    bool fl = 1;
    cin >> n;
    array<int, 102> ar;
    for (int i = 0; i < n; ++i)
        cin >> ar[i];
    for (int i = 1; i < n; ++i)
        switch (mak)
        {
        case 0:
            if (ar[i] < ar[i - 1])
                mak = 1;
            if (ar[i] == ar[i - 1])
                mak = 2;
            break;
        case 1:
            if (ar[i] >= ar[i - 1])
                fl = 0;
            break;
        case 2:
            if (ar[i] < ar[i - 1])
                mak = 1;
            if (ar[i] > ar[i - 1])
                fl = 0;
            break;
        }
    if (fl)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}