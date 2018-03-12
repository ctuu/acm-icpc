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