#include<iostream>
#include <array>
using namespace std;
const int N = 1007;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    array<bool, N> a;
    a.fill(0);
    int n, r;
    cin >> n >> r;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int st = -1;
    for(int i = 0; i < r; ++i)
        st = a[i] ? i: st;
    if(st == -1)
    {
        cout << "-1" << endl;
        return 0;
    }
    int ct = 1;
    while(st + r < n)
    {
        int te = -1;
        for(int i = st + 1; i < st + 2 * r && i < n; ++i)
            te = a[i] ? i: te;
        ++ct;
        if(te == -1)
        {
            cout << -1 << endl;
            return 0;
        }
        st = te;
    }
    cout << ct << endl;
    return 0;
}