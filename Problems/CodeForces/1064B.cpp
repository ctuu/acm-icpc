#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = 0;
        while(n)
        {
            ans += n&1;
            n>>=1;
        }
        cout << (int)pow(2,ans) << endl;
    }
    return 0;
}