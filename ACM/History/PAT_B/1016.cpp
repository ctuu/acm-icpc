#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string n1, n2;
    char t1, t2;
    cin >> n1 >> t1 >> n2 >> t2;
    stringstream nn1;
    nn1.str(n1);
    stringstream nn2;
    nn2.str(n2);
    char te;
    int nt1 = 0, nt2 = 0;
    while (nn1 >> te)
        if (te == t1)
            ++nt1;
    while (nn2 >> te)
        if (te == t2)
            ++nt2;
    long long sum = 0;
    long long st = 1;
    for (int i = 1; t1 != '0' && i <= nt1; ++i)
    {
        st *= (t1 - '0');
        sum += st;
        st /= (t1 - '0');
        st *= 10;
    }
    st = 1;
    for (int i = 1; t2 != '0' && i <= nt2; ++i)
    {
        st *= (t2 - '0');
        sum += st;
        st /= (t2 - '0');
        st *= 10;
    }
    cout << sum;
    return 0;
}
