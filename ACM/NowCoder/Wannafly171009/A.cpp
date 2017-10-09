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
    array<int, 100003> ar;
    cin >> n;
    int sum = n;
    for (int i = 0; i < n; ++i)
        cin >> ar[i];
    for (int i = 1; i < n; ++i)
    {
        if (sum - i < ar[i])
            sum += ar[i] - sum + i;
    }
    cout << sum;
    return 0;
}