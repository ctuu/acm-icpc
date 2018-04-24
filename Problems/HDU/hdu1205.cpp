#include <iostream>
#include <algorithm>
#include <array>
using namespace std;
using LL = long long;
const int N = 103;
array<LL, N + 7> d;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    d.fill(0);
    d[1] =1;
    d[2] = 3;
    for(int i = 3; i < N; ++i)
        d[i] = 3 * d[i-1] - d[i-2];
    int n;
    while(cin >> n)
        cout << d[n]<< endl;
    return 0;
}