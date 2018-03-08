#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;
using A = array<int, 9>;
int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
bool vis[362880];
string step[362880];
struct Po
{
    A ar;
    int x; 
    string s;
    Po(A ar, int x, string s) : ar(ar), x(x), s(s) {}
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
    qu.push(Po(oar, 8, ""));
    vis[cantor(oar)] = 1;
    step[cantor(oar)] = "lr";
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
                string ts = cu.s;
                ts.insert(ts.begin(), q[i]);
                int fl = cantor(tr);
                if (!vis[fl])
                {
                    vis[fl] = 1;
                    step[fl] = ts;
                    qu.push(Po(tr, cx + p[i], ts));
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
        int ans = cantor(ar);
        if (!vis[ans])
            cout << "unsolvable" << endl;
        else
            cout << step[ans] << endl;
    }
    return 0;
}