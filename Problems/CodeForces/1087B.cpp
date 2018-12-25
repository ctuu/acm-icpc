#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, x = 0x3f3f3f3f;
    cin >> n >> k;
    for(int i = 1; i < k; ++i)
    {
        if(n%i)
            continue;
        x = min(x, n / i * k + i);
    }
    cout << x << endl;
    return 0;
}