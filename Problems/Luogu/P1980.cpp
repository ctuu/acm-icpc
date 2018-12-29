#include <iostream>
#include <array>
#include <cmath>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    array<long long, 10> a;
    a.fill(0);
    long long n, x;
    cin >> n >> x;
    while(n--)
    {
        string s = to_string(n+1);
        for(auto i:s)
            a[i-'0']++;
    }
    cout << a[x] ;
    return 0;
}
