#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, sf, st;
    cin >> n >> k;
    sf = n;
    st = 2 * n;
    int aro = 0, art = 0;
    vector<int> arf;
    for (int i = 0; i < k; ++i)
    {
        int te, tf;
        cin >> te;
        if (te >= 4)
        {
            tf = te / 4;
            arf.push_back(tf);
            te %= 4;
        }
        if (te >= 2)
        {
            ++art;
            te -= 2;
        }
        aro += te;
    }

    while (aro > 0 && art && sf)
    {
        --aro;
        --art;
        --sf;
    }
    while (aro > 1 && sf)
    {
        aro -= 2;
        --sf;
    }
    while (aro)
    {
        --aro;
        --st;
    }
    for (auto &i : arf)
    {
        if (sf)
        {
            if (i >= sf)
            {
                i -= sf;
                sf = 0;
                st -= 2 * i;
            }
            else
                sf -= i;
        }
        else
            st -= 2 * i;
    }
    if (sf)
    {
        while (art >= 3 && sf >= 2)
        {
            art -= 3;
            sf -= 2;
        }
        if (art >= sf)
            art -= sf;
        else
            art = 0;
    }
    st -= art;
    if (sf >= 0 && st >= 0)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}