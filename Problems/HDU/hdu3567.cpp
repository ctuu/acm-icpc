#include <algorithm>
#include <array>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using A = array<int, 9>;
const int MN = 400000;
int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
bool vis[9][MN];
char step[9][MN];
int can[9][MN];
struct Po
{
    A ar;
    int x, ct;
    Po(A ar, int x, int ct) : ar(ar), x(x), ct(ct) {}
};

int cantor(A ar)
{
    int sum = 0;
    for (int i = 0; i < 9; ++i)
    {
        int rnk = 0;
        for (int j = i + 1; j < 9; ++j)
            if (ar[i] > ar[j])
                rnk++;
        sum += rnk * fact[8 - i];
    }
    return sum;
}

void bfs(string len)
{
    A oar;
    int id;
    for (int i = 0; i < 9; ++i)
    {
        if (len[i] == '0')
            id = i;
        oar[i] = len[i] - '0';
    }
    memset(vis[id], 0, sizeof(vis[id]));
    queue<Po> qu;
    qu.push(Po(oar, id, cantor(oar)));
    vis[id][cantor(oar)] = 1;
    while (!qu.empty())
    {
        Po cu = qu.front();
        qu.pop();
        int &cx = cu.x;
        int p[4] = {3, -1, 1, -3};
        char q[4] = {'d', 'l', 'r', 'u'};
        for (int i = 0; i < 4; ++i)
            if (cx + p[i] > -1 && cx + p[i] < 9)
            {
                if ((cx == 2 && p[i] == 1) || (cx == 5 && p[i] == 1) || (cx == 6 && p[i] == -1) || (cx == 3 && p[i] == -1))
                    continue;
                A tr = cu.ar;
                tr[cx] = tr[cx + p[i]];
                tr[cx + p[i]] = 0;
                // string ts = cu.s + q[i];
                int fl = cantor(tr);
                if (!vis[id][fl])
                {
                    vis[id][fl] = 1;
                    step[id][fl] = q[i];
                    can[id][fl] = cu.ct;
                    qu.push(Po(tr, cx + p[i], fl));
                }
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    bfs("012345678");
    bfs("102345678");
    bfs("120345678");
    bfs("123045678");
    bfs("123405678");
    bfs("123450678");
    bfs("123456078");
    bfs("123456708");
    bfs("123456780");
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        char ch;
        A ar, br, tr;
        int id, j = 0;
        for (int i = 0; i < 9; ++i, ++j)
        {
            cin >> ch;
            if (ch == 'X')
            {
                ar[i] = 0;
                id = i;
                tr[0] = 0;
                --j;
            }
            else
            {
                ar[i] = j + 1;
                tr[ch - '0'] = j + 1;
            }
        }
        for (int i = 0; i < 9; ++i)
        {
            cin >> ch;
            if (ch == 'X')
                br[i] = 0;
            else
                br[i] = tr[ch - '0'];
        }
        string san;
        int ans = cantor(ar);
        int bns = cantor(br);
        int tmp = bns;
        while(tmp != ans)
        {
            san = step[id][tmp] + san;
            tmp = can[id][tmp];
        }
        cout << "Case " << t << ": " << san.size() << endl;
        cout << san << endl;
    }
    return 0;
}