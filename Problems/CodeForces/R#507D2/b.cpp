#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int b = n / (2 * k + 1);
    b += n % (2 * k + 1) ? 1 : 0;
    cout << b << endl;
    int wy = b * (2 * k + 1) - n > k ? b * (2 * k + 1) - n - k : 0;
    for (int i = 1 + k - wy; i <= n; i += 2 * k + 1)
        cout << i << " ";
    cout << endl;
    return 0;
}