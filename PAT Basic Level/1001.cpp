#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i = 0, n;
    cin >> n;
    while (n != 1)
    {
        if (n % 2 == 0)
            n /= 2;
        else 
            n = (3 * n + 1) / 2;
        ++i;
        cout << n << " ";
    }
    return 0;
}
