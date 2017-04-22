#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string n;
    cin >> n;
    auto b = n.begin();
    auto e = n.end() - 1;
    int fl = 0;
    while (b <= e)
    {
        if (*b != *e)
        {
            ++fl;
            if (fl == 2)
            {
                cout << "NO";
                return 0;
            }
        }
        ++b;
        --e;
    }
    if (n.size() % 2 == 0 && fl == 0)
        cout << "NO";
    else
    cout << "YES";
    return 0;
}
