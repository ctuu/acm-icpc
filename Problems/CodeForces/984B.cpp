#include <array>
#include <iostream>
using namespace std;
const int N = 107;
array<array<char, N>, N> gr;
int n, m;
int d[8][2] = {-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1};
bool chk(int x, int y)
{
    int mc = 0;
    for (int i = 0; i < 8; ++i)
    {
        int cx = x + d[i][0];
        int cy = y + d[i][1];
        if (cx < 0 || cx >= n || cy < 0 || cy >= m)
            continue;
        mc = gr[cx][cy] == '*' ? mc + 1 : mc;
    }
    if (gr[x][y] == '*')
        return 1;
    if (gr[x][y] == '.')
        return mc > 0 ? 0 : 1;
    return mc == gr[x][y] - '0' ? 1 : 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> gr[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (!chk(i, j))
            {
                cout << "NO" << endl;
                return 0;
            }
    cout << "YES" << endl;
    return 0;
}