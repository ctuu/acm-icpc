#include <algorithm>
#include <array>
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    int k, sum = 0;
    array<char, 200003> cr;
    for (int i = 0; i < n; ++i)
        cin >> cr[i];
    k = cr[0] == '.' ? 1 : 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!a && !b)
            break;
        if (i < n && cr[i] == '.')
            k++;
        else
        {
            if (b > a)
                swap(a, b);
            if (a >= (k + 1) / 2)
            {
                a -= (k + 1) / 2;
                sum += (k + 1) / 2;
                k -= (k + 1) / 2;
            }
            else
            {
                sum += a + b;
                a = 0;
                b = 0;
                break;
            }

            if(b >= k)
            {
                b -= k;
                sum += k;
            }
            else
            {
                sum += b;
                b = 0;
            }
            k = 0;
        }
    }
    cout << sum << endl;
    return 0;
}