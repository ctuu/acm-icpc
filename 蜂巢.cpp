
#include <array>
#include <iostream>
#define M 10
using namespace std;
array<array<char, 2100>, 2100> lbx;
void draw(int x, int y, int n)
{
    if (n > 1)
    {
        draw(x - 1, y - 3, n - 1);
        draw(x - 1, y + 3, n - 1);
        draw(x + 1, y + 3, n - 1);
        draw(x + 1, y - 3, n - 1);
        draw(x - 2, y, n - 1);
        draw(x + 2, y, n - 1);
    }
    lbx[x][y] = lbx[x + 1][y + 3] = '/';
    lbx[x + 1][y] = lbx[x][y + 3] = '\\';
    lbx[x - 1][y + 1] = lbx[x - 1][y + 2] = '_';
    lbx[x + 1][y + 1] = lbx[x + 1][y + 2] = '_';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (auto &i : lbx)
        i.fill(' ');
    draw(2 * M - 1, 3 * M - 3, M);
    int n;
    while (cin >> n)
    {
        // for (auto &i : lbx)
        //     i.fill(' ');
        // draw(2 * n - 1, 3 * n - 3, n);
        for (int i = M - n; i <M - n +  4 * n - 1; ++i, cout << endl)
            for (int j = 0; j < 6 * n - 2; ++j)
                cout << lbx[i][j];
        // for (int i = 0; i < 4 * n - 1; ++i, cout << endl)
        //     for (int j = 0; j < 6 * n - 2; ++j)
        //         cout << lbx[i][j];
    }
    return 0;
}
