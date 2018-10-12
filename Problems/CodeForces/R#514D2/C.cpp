#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    stringstream s;
    if (n == 3)
        s << "1 1 3";
    else if (n == 2)
        s << "1 2";
    else if (n == 1)
        s << "1";
    else
    {
        s << "1";
        for (int i = 1; i < (n + 1) / 2; ++i)
            s << " 1";
        int ls = n - (n + 1) / 2;
        int k = 4;
        bool fl = 1;
        while (k <= n)
        {
            int a1 = n / k;
            int a2 = n / (k + k / 2);
            // cout << a1 << " " << a2 << endl;
            // cout << ls << endl;
            if (a1 > a2)
            {
                for (int i = a1; i < ls; ++i)
                    s << " " << k / 2;
                ls = a1;
            }
            else
            {
                for (int i = 1; i < ls; ++i)
                    s << " " << k / 2;
                s << " " << (k + k / 2);
                fl = 0;
                break;
            }
            k *= 2;
        }
        if (fl)
            s << " " << k / 2;
    }
    cout << s.str() << endl;
    return 0;
}