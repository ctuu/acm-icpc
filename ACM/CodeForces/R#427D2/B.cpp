#include <iostream>
#include <algorithm>
#include <array>
#include <cstdio>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k, n;
    char ch;
    array<int, 10> bu;
    bu.fill(0);
    cin >> k;
    cin.read(&ch, 1);
    while ((ch = getchar()) && ch != '\n')
    {
        n = ch - '0';
        ++bu[n];
        k -= n;
        if (k <= 0)
            break;
    }
    int ans = 0;
    if (k > 0)
    {
        for (int i = 0; i < 10 && k > 0; ++i)
        {
            k -= bu[i] * (9 - i);
            ans += bu[i];
            if (k < 0)
            {
                ans += k / (9 - i);
                break;
            }
        }
    }
    cout << ans;
    return 0;
}