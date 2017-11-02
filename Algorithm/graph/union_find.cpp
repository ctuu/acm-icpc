#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5;
array<int, N> p;

int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}
void joint(int a, int b)
{
    int i = find(a);
    int j = find(b);
    p[i] = j;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < N; ++i)
        p[i] = i;
    return 0;
}