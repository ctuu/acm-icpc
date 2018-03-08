#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Po
{
    int x, y;
    string s;
    Po() {}
    Po(int x, int y, string s) : x(x), y(y), s(s) {}
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m[7][7];
    bool v[7][7] = {0};
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            cin >> m[i][j];
    queue<Po> qu;
    qu.push(Po(0, 0, "(0, 0)\n"));
    v[0][0] = 1;
    while (!qu.empty())
    {
        Po cur = qu.front();
        qu.pop();
        if (cur.x == 4 && cur.y == 4)
        {
            cout << cur.s;
            return 0;
        }
        for (int i = -1; i < 2; i += 2)
            if (cur.x + i > -1 && cur.x + i < 5 && m[cur.x + i][cur.y] != 1 && !v[cur.x + i][cur.y])
            {
                qu.push(Po(cur.x + i, cur.y, cur.s + "(" + char(cur.x + i + '0') + ", " + char(cur.y + '0') + ")\n"));
                v[cur.x + i][cur.y] = 1;
            }
        for (int i = -1; i < 2; i += 2)
            if (cur.y + i > -1 && cur.y + i < 5 && m[cur.x][cur.y + i] != 1 && !v[cur.x][cur.y + i])
            {
                qu.push(Po(cur.x, cur.y + i, cur.s + "(" + char(cur.x + '0') + ", " + char(cur.y + i + '0') + ")\n"));
                v[cur.x][cur.y + i] = 1;
            }
    }
    return 0;
}