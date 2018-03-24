#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int n, xx;
array<int, 200300> pth;
int r[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
bool calc(int ty)
{
    int cx = pth[0] / ty + 1;
    int cy = pth[0] % ty;
    for (int i = 1; i < n; ++i)
    {
        bool fl = 1;
        int bx = pth[i] / ty + 1;
        int by = pth[i] % ty;
        xx = max(bx,xx);
        for (int j = 0; j < 4; ++j)
        {
            int dx = cx + r[j][0];
            int dy = cy + r[j][1];
            if (bx == dx && by == dy)
            {
                cx = bx;
                cy = by;
                fl = 0;
                break;
            }
        }
        if (fl)
            return 1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x, y, mn = 0;
    x = y = -1;
    xx = 0;
    int ty = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> pth[i];
        pth[i]--;
        mn = max(pth[i], mn);
    }
    for (int i = 1; i < n; ++i)
    {
        int t = abs(pth[i] - pth[i - 1]);
        ty = max(ty, t);
        if(t == 0)
        {
            cout << "NO" << endl;
            return 0;
        }    
    }
    if(ty <= 1)
    {
        cout << "YES" << endl
             << "1 " << mn + 1 << endl;
        return 0;
    }
    if (!calc(ty))
    {
        y = ty;
        x = 1000000000;
        cout << "YES" << endl;
        cout << x << " " << y << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}