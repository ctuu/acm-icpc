#include <bits/stdc++.h>
using namespace std;
bool prim[1000002] = {0};
void mpn();
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    mpn();
    int a, b, i, j = 0;
    cin >> a >> b;
    for (int i = 2; i < 1000002; ++i)
    {
        if (!prim[i])
        {
            ++j;
            if (j >= a)
            {
                if ((j - a) % 10 == 0 && (j - a) != 0)
                    cout << endl;
                else if (j > a)
                    cout << " ";
                cout << i;
            }
            if (j == b)
                break;
        }
    }
    cout << "!";
    return 0;
}

void mpn()
{
    prim[1] = prim[0] = 1;
    for (int i = 2; i < 50001; ++i)
    {
        if (prim[i])
            continue;
        for (int j = 2 * i; j < 1000002; j += i)
            prim[j] = 1;
    }
}
