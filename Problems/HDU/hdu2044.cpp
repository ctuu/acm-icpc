#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--)
    {
        long long a, b, c = 0;
        cin >> a >> b;
        b -= a -2;
        a = 1;
        while (b--)
        {
            a += c;
            a += c, c = a - c, a -= c;
        }
        cout << a << endl;
    }
    return 0;
}