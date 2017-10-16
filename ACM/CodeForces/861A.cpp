#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, k;
    cin >> n >> k;
    long long ba = 1;
    for (int i = 0; i < k; ++i)
        ba *= 10;
    cout << n * ba / __gcd(n, ba);
    return 0;
}