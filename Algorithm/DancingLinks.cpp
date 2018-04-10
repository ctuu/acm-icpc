#include <algorithm>
#include <iostream>
// #include <array>
#include <vector>
#define N 1001
#define M 1001
using namespace std;
int lc[N], lr[M];
int n, m;

struct No {
    int l, r, u, d,cl, rw;
};
vector<No> lks;
int cnt = 0;
void add(No & d, int cl, int cr)
{
    d.l = lc[cr];// 当前行的前一列
    d.u = lr[cl];
    d.cl = cl;
    d.rw = cr;
    d.r = d.d = 0;
    lks[lr[cl]].d = cnt;
    lks[lc[cr]].r = cnt;
    lc[cr] = cnt;
    lr[cl] = cnt;

}
// void add(int c, int cl, int cr)
// {
//     l[c] = lc[cr];
//     u[c] = lr[cl];
//     col[c] = cl;
//     row[c] = cr;
//     r[c] = 0;
//     d[c] = 0;
//     d[lr[cl]] = c;
//     r[lc[cr]] = c;
// }



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ct = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            int k, tmp;
            cin >> k;
            while (k--)
            {
                ++ct;
                cin >> tmp;
                add(ct, i, tmp);
            }
        }
    return 0;
}