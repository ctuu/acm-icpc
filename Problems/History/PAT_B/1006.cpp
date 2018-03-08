#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    array <int, 3> an;
    an[0] = n/100;
    an[1] = n/10 - an[0] * 10; 
    an[2] = n%10;
    for (int i = 0; i < an[0]; ++i)
        cout << 'B';
    for (int i = 0; i < an[1]; ++i)
        cout << 'S';
    for (int i =1; i <= an[2]; ++i)
        cout << i;        
    return 0;
}
