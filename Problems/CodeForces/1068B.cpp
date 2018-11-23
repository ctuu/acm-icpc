#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long long b;
    cin >> b;
    long long ans = 0;
    long long sqr = sqrt(b);
    for (long long k = 1; k <= sqr; ++k)
    {
        if (b % k == 0)
        {
            ++ans;
            if (k * k != b)
                ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}