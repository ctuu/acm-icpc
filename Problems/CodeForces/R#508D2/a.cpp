#include <algorithm>
#include <array>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    array<int, 26> a;
    a.fill(0);
    for (auto c : s)
        a[c - 'A']++;
    sort(a.begin(), a.end());
    int ans = k * *(a.rbegin() + k - 1);
    cout << ans << endl;
    return 0;
}