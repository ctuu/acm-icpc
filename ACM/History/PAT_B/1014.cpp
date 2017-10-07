#include <bits/stdc++.h>
#include <cctype>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    int i, n;
    string week[7] = {"MON ", "TUE ", "WED ", "THU ", "FRI ", "SAT ", "SUN "};
    cin >> a >> b;
    n = min(a.size(), b.size());
    for (i = 0; i < n; ++i)
       if (a[i] == b[i] && isupper(a[i]) && a[i] <= 'G')
        {
            cout << week[a[i] - 'A'];
            break;
        }
    for (++i; i < n; ++i)
        if (a[i] == b[i] && isdigit(a[i])) 
        {
            cout << '0' << a[i];
            break;
        }
        else if (a[i] == b[i] && isupper(a[i]) && a[i] <= 'N')
        {
            cout << (10 + a[i] - 'A');
            break;
        }
    cout << ":";
    cin >> a >> b;
    n = min(a.size(), b.size());
    for (i = 0; i < n; ++i)
        if (a[i] == b[i] && isalpha(a[i]))
        {
            cout << setw(2) << setfill('0') << i;
            break;
        }
    return 0;
}
