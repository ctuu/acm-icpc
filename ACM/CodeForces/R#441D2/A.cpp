#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    n--;
    int sum = 0;
    int minm = min(a, b);
    if (n)
    {
        sum += minm;
        n--;
    }
    minm = min(minm, c);
    sum += minm * n;
    cout << sum;
    return 0;
}