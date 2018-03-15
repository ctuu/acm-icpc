#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
array<int, 32> g{{11, 12, 13, 14, 15, 16, 17, 0,
                  21, 22, 23, 24, 25, 26, 27, 0,
                  31, 32, 33, 34, 35, 36, 37, 0,
                  41, 42, 43, 44, 45, 46, 47, 0}};
struct It
{
    array<int, 32> ar;
    array<int, 4> sp;
    int t;
};
string hs(array<int, 32> ar)
{
    string s;
    for (auto i : ar)
        s += to_string(i);
    return s;
}
void show(array<int, 32> ar)
{
    for (int i = 0; i < 32; ++i)
    {
        cout << ar[i] << " ";
        if (i == 7 || i == 15 || i == 23 || i == 31)
            cout << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    It cu;
    while (T--)
    {
        map<string, bool> tg;
        string sg = hs(g);
        tg[sg] = 1;
        int t = 0;
        for (int i = 1; i < 32; ++i)
        {
            if (i == 8 || i == 16 || i == 24)
                continue;
            cin >> cu.ar[i];
            if (cu.ar[i] % 10 == 1)
            {
                cu.ar[(cu.ar[i] / 10 - 1) * 8] = cu.ar[i];
                cu.ar[i] = 0;
                cu.sp[t++] = i;
            }
        }
        int ans = -1;
        string ts = hs(cu.ar);
        if (ts == sg)
            ans = 0;
        cu.t = 0;
        queue<It> qu;
        qu.push(cu);
        while (!qu.empty())
        {
            auto cu = qu.front();
            qu.pop();
            if (ans != -1)
                break;
            for (int i = 0; i < 4; ++i)
            {
                It tmp = cu;
                tmp.t++;
                int num = tmp.ar[tmp.sp[i] - 1];
                if (num % 10 != 7)
                    for (int j = 0; j < 32; ++j)
                        if (tmp.ar[j] == num + 1)
                        {
                            tmp.ar[j] = 0;
                            tmp.ar[tmp.sp[i]] = num+1;
                            tmp.sp[i] = j;
                            break;
                        }
                string ts = hs(tmp.ar);
                if (ts == sg)
                {
                    ans = tmp.t;
                    break;
                }
                if (!tg[ts])
                {
                    tg[ts] = 1;
                    qu.push(tmp);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}