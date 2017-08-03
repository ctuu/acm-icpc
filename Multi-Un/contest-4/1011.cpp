#include <iostream>
#include <algorithm>
#include <array>
#define R 21
#define C 7
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    array<array<char, R>, C> cl;
    array<array<int, 4>, C> dl;
    while (t--)
    {
        for (int i = 0; i < C; ++i)
            for (int j = 0; j < R; ++j)
                cin >> cl[i][j];
        for (auto &i : dl)
            i.fill(0);

        for (int i = 0; i < C; ++i)
        {
            int r = 8;
            for (int j = 0; j <= 3; ++j)
            {
                if (cl[i][j] == 'X')
                    dl[i][0] += r;
                r >>= 1;
            }
            for (int j = 5, r = 8; j <= 8; ++j)
            {
                if (cl[i][j] == 'X')
                    dl[i][1] += r;
                r >>= 1;
            }
            for (int j = 12, r = 8; j <= 15; ++j)
            {
                if (cl[i][j] == 'X')
                    dl[i][2] += r;
                r >>= 1;
            }
            for (int j = 17, r = 8; j <= 20; ++j)
            {
                if (cl[i][j] == 'X')
                    dl[i][3] += r;
                r >>= 1;
            }
        }
        array<array<int, 3>, 4> el;
        for (auto &i : el)
            i.fill(0);
        for (int i = 0; i < 4; ++i)
        {
            el[i][0] = dl[0][i] * 256 + dl[1][i] * 16 + dl[2][i];
            el[i][1] = dl[3][i];
            el[i][2] = dl[4][i] * 256 + dl[5][i] * 16 + dl[6][i];
        }
        for (int i = 0; i < 4; ++i)
        {
            if (i == 2)
                cout << ":";
            if (el[i][0] == 17)
                cout << 1;
            else if (el[i][0] == 153)
                cout << 4;
            else if (el[i][0] == 1553 && el[i][1] == 0)
                cout << 7;
            else if (el[i][0] == 1553 && el[i][2] == 2182)
                cout << 2;
            else if (el[i][0] == 1553 && el[i][2] == 278)
                cout << 3;
            else if (el[i][0] == 1689 && el[i][1] == 0)
                cout << 0;
            else if (el[i][0] == 1689 && el[i][2] == 2454)
                cout << 8;
            else if (el[i][0] == 1689 && el[i][2] == 278)
                cout << 9;
            else if (el[i][2] == 278)
                cout << 5;
            else
                cout << 6;
        }
        cout << endl;
    }
    return 0;
}