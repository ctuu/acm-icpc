#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;
using A = array<int, 9>;
const int INF = 0x3f3f3f3f;
const int MN = 400000;
int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
bool vis[MN];
// string step[362880];
char step[MN];
int can[MN];
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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    A oar;
    for (int i = 0; i < 8; ++i)
        oar[i] = i + 1;
    oar[8] = 0;
    queue<Po> qu;
    int aim = cantor(oar);
    qu.push(Po(oar, 8, aim));
    vis[aim] = 1;
    while (!qu.empty())
    {
        Po cu = qu.front();
        qu.pop();
        int &cx = cu.x;
        int p[4] = {-1, 1, -3, 3};
        char q[4] = {'r', 'l', 'd', 'u'};
        for (int i = 0; i < 4; ++i)
            if (cx + p[i] > -1 && cx + p[i] < 9)
            {
                if ((cx == 2 && i == 1) || (cx == 5 && i == 1) || (cx == 6 && i == 0) || (cx == 3 && i == 0))
                    continue;
                A tr = cu.ar;
                tr[cx] = tr[cx + p[i]];
                tr[cx + p[i]] = 0;
                int fl = cantor(tr);
                if (!vis[fl])
                {
                    vis[fl] = 1;
                    step[fl] = q[i];
                    can[fl] = cu.ct;
                    qu.push(Po(tr, cx + p[i], fl));
                }
            }
    }
    // cout <<"!!!"<<endl;
    stringstream foo;
    string lin;
    while (getline(cin, lin))
    {
        lin.replace(lin.find('x'), 1, "0");
        foo.clear();
        foo.str(lin);
        A ar;
        for (int i = 0; i < 9; ++i)
            foo >> ar[i];
        int tmp = cantor(ar);
        if (!vis[tmp])
            cout << "unsolvable" << endl;
        else
        {
            string san = "";
            while (tmp != aim)
            {
                san += step[tmp];
                tmp = can[tmp];
            }
            cout << san << endl;
        }
    }
    return 0;
}