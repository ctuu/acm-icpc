#include <bits/stdc++.h>
using namespace std;

int main()
{
    int maxd, x;
    string qu;
    bool fl = 0;
    while (cin >> qu)
    {
        fl = 0;
        int curd = 0;
        maxd = 0;
        for (x = 0; x < qu.size(); ++x)
        {
            if (curd < 0)
            {
                fl = 1;
                break;
            }
            if (qu[x] == '(')
            {
                ++curd;
            }
            else
            {
                maxd = max(maxd, curd);
                --curd;
            }
        }
        if (qu[0] == ')' || qu[x - 1] == '(' || curd != 0)
        fl = 1;
        if (fl == 0)
            cout <<"YES " << maxd << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}