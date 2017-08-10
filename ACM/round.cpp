#include <bits/stdc++.h>
using namespace std;

bool round(int x, int y);
int R;
int main()
{
    cin >> R;
    for (int i = 0; i <= 2 * R; ++i)
    {
        for (int j = 0; j <= 2 * R; ++j)
            cout << (round(i, j)? "*":" ") << " ";
        cout << endl;
    }
    return 0;
}

bool round(int x, int y)
{
    int k = (x - R) * (x - R) + (y - R) * (y - R);
    if (R * R - k >= 0 && R * R - k <= R*1)
        return 1;
    return 0;
}

