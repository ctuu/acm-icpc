#include <iostream>
#include <vector>
using namespace std;
bool prim[100001] = {0};
void mpn(void);
int main()
{
    mpn();
    int n, k;
    cin >> n >> k;
    --k;
    vector<int> ti;
    for (int j = 0; j < k; ++j)
    {
        for (int i = 2; i < 100001; ++i)
            if (prim[i] == 0 && n >= i && n % i == 0)
            {
                ti.push_back(i);
                n /= i;
                break;
            }
    }
    if (n == 1)
        ++k;
    if (ti.size() < k)
        cout << -1;
    else
    {
        for (auto i : ti)
            cout << i << " ";
        cout << n;
    }
    return 0;
}

void mpn(void)
{
    prim[0] = prim[1] = 1;
    int i, j;
    for (i = 2; i < 50001; ++i)
    {
        if (prim[i] == 1)
            continue;
        for (j = 2 * i; j < 100001; j += i)
                prim[j] = 1;
    }
}
