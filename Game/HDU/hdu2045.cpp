#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n)
    {
        long long sum = 1;
        if (n == 1)
        {
            cout << 3 << endl;
            continue;
        }
        for (int i = 0; i < n; ++i)
            sum <<= 1;
        if (n & 1)
            sum -= 4;
        sum += 2;
        cout << sum << endl;
    }
    return 0;
}