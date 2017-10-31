#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    array<bool, 100005> ar;
    ar.fill(0);
    for (int a = 1, b = 1; a < 100005 && b < 100005; swap(a, b))
    {
        ar[a] = 1;
        a += b;
    }
    for(int i = 0; i < 20;++i)
    if(ar[i])
    cout << i << " ";
    return 0;
}