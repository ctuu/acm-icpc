#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int n, ans, clen;
array<string, 10> ch;
char dna[4] = {'A', 'C', 'G', 'T'};
void dfs(int cu, array<int, 10> le)
{
    int anf = 0;
    for (int i = 0; i < n; ++i)
        anf = max(anf, (int)ch[i].size() - le[i]);
    if (anf == 0)
    {
        ans = cu;
        return;
    }
    if (cu + anf > clen)
        return;
    for (int i = 0; i < 4; ++i)
    {
        array<int, 10> nxt = le;
        bool fl = 0;
        for (int j = 0; j < n; ++j)
        {
            if (ch[j][le[j]] == dna[i])
            {
                fl = 1;
                ++nxt[j];
            }
        }
        if (fl)
            dfs(cu + 1, nxt);
        if (ans != -1)
            return;
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
        ans = -1;
        clen = 0;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> ch[i];
            clen = max(clen, (int)ch[i].size());
        }
        array<int, 10> cu;
        cu.fill(0);
        while (1)
        {
            dfs(0, cu);
            if (ans != -1)
                break;
            clen++;
        }
        cout << ans << endl;
    }
    return 0;
}