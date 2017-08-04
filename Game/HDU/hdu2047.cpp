#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n)
    {
        long long a, c = 3;
        a = 1;
        while (n--)
        {
            a = 2 * (a + c);
            a += c, c = a - c, a -= c;
        }
        cout << a << endl;
    }
    return 0;
}