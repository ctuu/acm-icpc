#include <bits/stdc++.h>
#include <cctype>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string week[7] = {"MON ", "TUE ", "WED ", "THU ", "FRI ", "SAT ", "SUN "};
    string a, b;
    bool flag = 0;
    cin >> a >> b;
    int n = min(a.size(), b.size());
    for (int i = 0; i < n; ++i)
    {
        if (!flag && a[i] == b[i] && isupper(a[i]) && a[i] <= 'G')
        {
            cout << week[a[i] - 'A'];
            flag = 1;
        }
        else if (flag && a[i] == b[i])
        {
            if (isdigit(a[i]))
                cout << '0' << a[i];
            else if (isupper(a[i]) && a[i] <= 'N')
                cout << (10 + a[i] - 'A');
            break;
        }
    }
    cout << ":";
    cin >> a >> b;
    n = min(a.size(), b.size());
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == b[i] && islower(a[i]))
        {
            if (i < 10)
                cout << '0';
            cout << i;
            break;
        }
    }
    return 0;
}
