#include <algorithm>
#include <array>
#include <iostream>
using namespace std;
array<int, 200004> ar;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ar.fill(0);
    cin >> ar[0];
    for (int i = 1; i < n; ++i)
    {
        cin >> ar[i];
        ar[i] += ar[i - 1];
    }
    int l = 0, r = n;
    int trg = ar[n - 1];
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (ar[mid] * 2 >= trg)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l + 1 << endl;
    return 0;
}