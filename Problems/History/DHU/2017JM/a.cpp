#include <bits/stdc++.h>
using namespace std;

int main()
{
    string word[121];
    string ch[5] = {"D","E","E","S","T"};
    int i, j, k, m, n, l = 0;
    bool ie, je, ke, me, ne;
    ie = 0;
    for (i = 0; i < 5; ++i)
    {
        if (ie && i == 2)
            continue;
        if (i == 1)
            ie = 1;
        je = 0;
        for (j = 0; j < 5; ++j)
        {
            if (j == i)
            continue;
            if (je && j == 2)
                continue;
            if (j == 1)
                je = 1;
            ke = 0;
            for (k = 0; k < 5; ++k)
            {
                if (k == i || k == j)
                    continue;
                if (ke && k == 2)
                    continue;
                if (k == 1)
                    ke = 1;
                me = 0;                    
                for (m = 0; m < 5; ++m)
                {
                    if (m == i || m == j || m == k)
                    continue;
                    if (me && m == 2)
                        continue;
                    if (m == 1)
                        me = 1;
                    ne = 0;
                    for (n = 0; n < 5; ++n)
                    {
                        if (n == i || n == j || n == k || n == m)
                        continue;
                        if (ne && n == 2)
                            continue;
                        if (n == 1)
                            ne = 1;
                        word[l] = ch[i] + ch[j] + ch[k] + ch[m] + ch[n];
                        ++l;
                    }
                }
            }
        }
    }
    int num;
    while (cin >> num)
    cout << word[num - 1] << endl;
    return 0;
}