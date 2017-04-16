#include <iostream>
using namespace std;

bool hole[1000001] = {0};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    while (m--)
    {
        int i;
        cin >> i;
        hole[i] = 1;
    }
    int inpo = 1;
    while (k--)
    {
       int a, b;
       cin >> a >> b;
       if (hole[inpo])
           break;
       if (a == inpo)
           inpo = b;
       else if (b == inpo)
           inpo = a; 
    }
    cout << inpo;
    return 0;
}
