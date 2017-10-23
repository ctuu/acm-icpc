#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m)
    {
        int flag = 0, x = 0, y = 0;
        long long ans = 0;
        do
        {
            switch (flag)
            {
            case 0:
                if (n - x < m - y)
                {
                    ans += n - x;
                    y += n - x;
                    x = n;
                    flag = 1;
                }
                else
                {
                    x += m - y;
                    y = m;
                    flag = 3;
                }
                break;
            case 1:
                if (n < m - y)
                {
                    
                }
                else
                {
                
                }
                break;
            case 2:
                break;
            case 3:
                break;
            }
        } while (~(x == 0 && (y == 0 || y == m) || x == n && (y == 0 || y == m)))
                cout
            << ans << endl;
    }
    return 0;
}