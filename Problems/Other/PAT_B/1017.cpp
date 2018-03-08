#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string anu, res;
    int dior, rema = 0;
    cin >> anu >> dior;
    for (int i = 0; i < anu.size(); ++i)
    {
        if (!i)
            if (anu[i] - '0' < dior)
            {
                rema = anu[i] - '0';
                continue;
            }
        int nu = rema * 10 + (anu[i] - '0');
        res.push_back((nu / dior + '0')); 
        rema = nu % dior;
    }
    if (anu.size() == 1 && anu[0] - '0' <  dior)
        cout << "0" << " " << anu[0];
    else
        cout << res << " " << rema;
    return 0;
}
