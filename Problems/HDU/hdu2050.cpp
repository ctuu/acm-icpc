#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    array<long long, 10004> s;
    s.fill(0);
    s[1] = 2;
    for (int i = 2; i < 10004; ++i)
        s[i] = s[i - 1] + 2 + (i - 1) * 2 + 2 * (i - 2) + 1;
    int c, n;
    cin >> c;
    while (c--)
    {
        cin >> n;
        cout << s[n] << endl;
    }
    return 0;
}