#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#define N 105
using namespace std;
struct no
{
    int a, b, c, ab, bc, ac, abc;
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    no cl;
    while (t--)
    {
        int n, ans = 0;
        cin >> n;
        while (n--)
        {
            int oa, ob, oc, oab, obc, oac, tans = 0;
            cin >> cl.a >> cl.b >> cl.c >> cl.ab >> cl.bc >> cl.ac >> cl.abc;
            oab = cl.ab - cl.abc;
            obc = cl.bc - cl.abc;
            oac = cl.ac - cl.abc;
            oa = cl.a - oab - oac - cl.abc;
            ob = cl.b - oab - obc - cl.abc;
            oc = cl.c - oac - obc - cl.abc;
            // cout << oa << " " << ob << " " << oc << endl;
            // cout << oab << " " << obc << " " << oac << endl;
            if (oa >= 0 && ob >= 0 && oc >= 0 && oab >= 0 && oac >= 0 && obc >= 0 && cl.abc >= 0)
                tans = oa + ob + oc + oab + obc + oac + cl.abc;
            ans = max (ans, tans);
            // cout << cl.abc << " " << tans << endl;
        }
        cout << ans << endl;
    }
    return 0;
}