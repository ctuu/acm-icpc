#include <iostream>
#include <string>
#include <array>
#define M 10
using namespace std;
void draw(int x, int y, int level);
array<array<char, 2100>, 2100> xrbs;
int xn[12] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
     for (auto &i: xrbs)
        for (auto &k: i)
             k = ' ';
    draw(1, xn[M],M);
    bool ju = 0;
    while (cin >> n)
    {
        if (n == 0)
        return 0;
        if (ju)
            cout << endl;
        ju = 1;
        int k = xn[n];
        for (int i = 1 + xn[M] - xn[n]; i <= xn[M]; ++i)
        {
            int j;
            --k;
            for (j = 1; j <= xn[n + 1]; ++j)
            {
                cout << xrbs[i][j];
                if (j >= xn[n+1] - k)
                    break;
            }
                cout << endl;
        }
    }
    return 0;
}

void draw(int x, int y, int level)
{
    if (level > 1)
    {
        draw(x, y, level - 1);
        draw(x + xn[level - 1], y - xn[level - 2] - (xn[level - 1]/2), level - 1);
        draw(x + xn[level - 1], y + xn[level - 2] + (xn[level - 1]/2), level - 1);
    }
    else
    {
        xrbs[x][y] = xrbs[x + 1][y - 1] = '/';
        xrbs[x][y + 1] = xrbs[x + 1][y + 2] = '\\';
        xrbs[x + 1][y] = xrbs[x + 1][y + 1] = '_';
    }
    return;
}