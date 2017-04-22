#include <bits/stdc++.h>
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
        if (!flag && a[i] == b[i] && 'A' <= a[i] && a[i] <= 'Z')
        {
            cout << week[a[i] - 'A'];
            flag = 1;
        }
        else if (flag && a[i] == b[i])
        {
            if ('0' <= a[i] && a[i] <= '9')
                cout << a[i];
            else if ('A' <= a[i] && a[i] <= 'N')
                cout << (10 + a[i] - 'A');
        }
    }
    cout << ":";
    cin >> a >> b;
    n = min(a.size(), b.size());
   for (int i = 0; i < n; ++i)
   {
       if (a[i] == b[i] && 'a' <= a[i] && a[i] <= 'z')
       {
           if (i < 10)
               cout << '0';
            cout << i;
            break;
       }
   }
    return 0;
}
