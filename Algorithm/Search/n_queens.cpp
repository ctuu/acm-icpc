#include <iostream>
using namespace std;
int n, co;
void find(int x, int shu, int pie, int na);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n && n)
    {
        co = 0;
        find(0, 0, 0, 0);
        cout << co << endl;
    }
    return 0;
}

void find(int x, int shu, int pie, int na)
{
    int avail = ((1 << n) - 1) & ~(shu | pie | na);
    while (avail)
    {
        int p = avail & -avail;
        avail ^= p;
        if (x == n - 1)
            ++co;
        else
            find(x + 1, shu | p, (pie | p) >> 1, (na | p) << 1);
    }
}