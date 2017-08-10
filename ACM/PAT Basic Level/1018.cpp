#include <bits/stdc++.h>
using namespace std;

int comp(char a, char b);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int jy[2][3] = {0};
    int to[2][3] = {0};
    char a, b;
    int n;
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        ++to[0][comp(a, b)];
        ++to[1][comp(b, a)];
        if (comp(a, b) == 0)
        {
            if (a == 'B')
                ++jy[0][0];
            else if (a == 'C')
                ++jy[0][1];
            else if (a == 'J')
                ++jy[0][2];
        }
        else if (comp(b, a) == 0)
        {
            if (b == 'B')
                ++jy[1][0];
            else if (b == 'C')
                ++jy[1][1];
            else if (b == 'J')
                ++jy[1][2];
        }

    }
    for (int i = 0; i <= 1; ++i)
    {
        for (int j = 0; j <= 2; ++j)
        {
            if (j != 0)
                cout << " ";
            cout << to[i][j];
        }
        cout << endl;
    }

    char wo[] = "BCJ"; 
    for (int i = 0; i <= 1; ++i)
    {
        int te = 0;
        int tt = jy[i][0];
        for (int j = 1; j <= 2; ++j)
        {
            if (tt < jy[i][j])
            {
                tt = jy[i][j];
                te = j;
            }
        }
        if (i != 0)
            cout << " ";
        cout << wo[te];
    }
    return 0;
}

int comp(char a, char b)
{
    if (a == b)
        return 1;
    if (a == 'B')
    {
        if (b == 'C')
            return 0;
        else
            return 2;
    }
    if (a == 'C')
    {
        if (b == 'J')
            return 0; 
        else
            return 2;
    }
    if (a == 'J')
    {
        if (b == 'B')
            return 0;
        else
            return 2;
    }
    return 0;
}
