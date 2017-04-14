#include <bits/stdc++.h>
using namespace std;
int main()
{
    array<int, 8> fi;
    fi.fill(5);
    for (int i = 1; i < 8; ++i)
        fi[i] *= fi[i-1];
    int num;
    cin >> num;
    int la = 1;
    for (int i = 1; i <= num; ++i)
    {
        if (i >= 5 && i % 5 == 0)
        {
            for (int j = 7; j > -1; --j)
                if (i >= fi[j] && i % fi[j] == 0) 
                {
                    la /= ((j + 1) * 2);
                    la *= i / fi[j];
                    cout << la << " " << j << endl;
                    continue;
                }
                la %= 10;
        }
        else
            la *= i;
        la %= 10;
    }
    cout << la;
    return 0;
}
