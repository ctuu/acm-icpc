#include <bits/stdc++.h>
using namespace std;
int main()
{
    array<int, 31> tw;
    tw.fill(2);
    tw[0] = 1;
    for (int i = 1; i < 31; ++i)
        tw[i] *= tw[i-1];
    // for (auto i : tw)
    //     cout << i << " ";
    int qu;
    while (cin >> qu)
    {
        int re = 0;
        for (int i = 30; i > -1; --i)
        {
            if (qu == 0)
                break;
            if (qu >= tw[i])
            {
                qu -= tw[i];
                ++re;
            }
        }
        cout << re << endl;
    }
    return 0;
}