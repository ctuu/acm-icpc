#include <array>
#include <cmath>
#include <iostream>
using namespace std;
const int N = 1e6 + 7;
array<int, N> ar, br;
int n, d = 0;
bool jd(int a, int b, int x, int y)
{
    if(a < 1 || b < 1 || x < 1 || y < 1 || x > a || y > b)
        return false;
    br.fill(0);
    for (int i = 1; i <= a; ++i)
        for (int j = 1; j <= b; ++j)
            br[abs(i - x) + abs(j - y)]++;
    for (int i = 1; i <= d; ++i)
        if (ar[i] != br[i])
            return false;
    return true;
}

int main()
{
    cin >> n;
    ar.fill(0);
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        ar[k]++;
        d = max(d, k);
    }
    if (ar[0] != 1 || ar[d] > 4 || ar[d] == 3)
    {
        cout << "-1" << endl;
        return 0;
    }

    int p = 1;
    while (ar[p] == 4 * p)
        ++p;
    int an = -1, am = -1, ax = -1, ay = -1;
    for (int i = 2 * p - 1; i * i <= n; ++i)
    {
        if (n % i)
            continue;
        int j = n / i, y = i + j - p - d;
        if (jd(i, j, p, y))
            an = i, am = j, ax = p, ay = y;
        else if (jd(i, j, y, p))
            an = i, am = j, ax = y, ay = p;
        if (an != -1)
            break;
    }

    if (an == -1)
        cout << "-1";
    else
    {
        cout << an << " " << am << endl;
        cout << ax << " " << ay << endl;
    }
    return 0;
}