#include <iostream>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    long long ans = k / n;
    if(k < n || k % n)
        ++ans;
    cout << ans << endl;
    return 0;
}