#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    int k = n / a + 1, j = 0;
    if (n % a == 0)
    {
        cout << "YES\n"
             << n / a << " 0" << endl;
        return 0;
    }
    if (n % b == 0)
    {
        cout << "YES\n"
             << "0 " << n / b << endl;
        return 0;
    }
    while (k--)
    {
        int tmp = (n - (k * a));
        if (tmp%b==0)
        {
            j = tmp/b;
            break;
        }
    }
    if (j)
    {
        cout << "YES" << endl;
        cout << k << " " << j << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}