#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
using CUBE = array<array<array<char, 3>, 3>, 6>;
using PII = pair<int, int>;
vector<PII> stp;
int ans = 0;
char cuid[6] = {'r', 'g', 'b', 'o', 'w', 'y'};

void dfs(int cd, CUBE cu)
{
    if (cd > 5)
        return;
}
bool reach(CUBE cu)
{
    for (int i = 0; i < 6; ++i)
    {
        char ch = cu[i][0][0];
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
                if (cu[i][j][k] != ch)
                    return 0;
    }
    return 1;
}
CUBE rotate(int idx, int dir, CUBE cu)
{
    int tmp[3];
    if (idx == 0)
    {
        if (dir == 1)
        {
            for (int i = 0; i < 3; ++i)
            {
                tmp[i] = cu[4][i][0];
                cu[4][i][0] = cu[3][3 - i][2];
                cu[3][3 - i][2] = cu[5][i][0];
                cu[5][i][0] = cu[1][i][0];
                cu[1][i][0] = tmp[i];
            }
        }
        else
            for (int i = 0; i < 3; ++i)
            {
                tmp[i] = cu[1][i][0];
                cu[1][i][0] = cu[5][i][0];
                cu[5][i][0] = cu[3][3 - i][2];
                cu[3][3 - i][2] = cu[4][i][0];
                cu[4][i][0] = tmp[i];
            }
    }
    if (idx == 1)
    {
        if (dir == 1)
        {
            for (int i = 0; i < 3; ++i)
            {
                tmp[i] = cu[4][2][i];
                cu[4][2][i] = cu[0][3 - i][2];
                cu[0][i][2] = cu[5][0][i];
                cu[5][0][3 - i] = cu[2][i][0];
                cu[2][i][0] = tmp[i];
            }
        }
        else
            for (int i = 0; i < 3; ++i)
            {
                tmp[i] = cu[2][i][0];
                cu[2][i][0] = cu[5][0][3 - i];
                cu[5][0][i] = cu[0][i][2];
                cu[0][3 - i][2] = cu[4][2][i];
                cu[4][2][i] = tmp[i];
            }
    }
    if (idx == 2)
    {
        if (dir == 1)
        {
            for (int i = 0; i < 3; ++i)
            {
                tmp[i] = cu[4][2][3-i];
                cu[4][2][3-i] = cu[0][3 - i][2];
                cu[0][3 - i][2] = cu[5][0][i];
                cu[5][0][3 - i] = cu[2][i][0];
                cu[2][i][0] = tmp[i];
            }
        }
        else
            for (int i = 0; i < 3; ++i)
            {
                tmp[i] = cu[2][i][0];
                cu[2][i][0] = cu[5][0][3 - i];
                cu[5][0][i] = cu[0][i][2];
                cu[0][3 - i][2] = cu[4][2][i];
                cu[4][2][i] = tmp[i];
            }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        stp.clear();
        ans = 0;
        CUBE cu;
        for (auto &i : cu[4])
            for (auto &j : i)
                cin >> j;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 4; ++j)
                for (int k = 0; k < 3; ++k)
                    cin >> cu[j][i][k];
        for (auto &i : cu[5])
            for (auto &j : i)
                cin >> j;
        dfs(0, cu);
    }
    return 0;
}