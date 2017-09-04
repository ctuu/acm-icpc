#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n, k;
    int vi[10002];
    for (int i = 1; i < n; ++i)
    cin >> vi[i];
    dp[vi[i] % k] = 1;
    bool dp[103] ={0};
    for (int i = 0; i < n; ++i)
        for (int j = k; j >= 0; ++j)
    return 0;
}