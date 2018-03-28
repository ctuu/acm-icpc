#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
const int N = 100005;
array<int, N> atr;
int n;
int lowbit(int i)
{
    return i & -i;
}

void add(int x,int v)
{
    for(int i = x; i <= n; i += lowbit(i))
        atr[i] += v;
}

int sum(int x)
{
    int s = 0;
    for(int i = x; i; i -= lowbit(i))
        s += atr[i];
    return s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 33;
    for(int i = 0; i < n; ++i)   
        cout << lowbits(i) << endl;
    return 0;
}