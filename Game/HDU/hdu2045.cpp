#include <iostream>
using namespace std;
int sum = 0, n;
void foo(int i, int j, int k)
{
    if (i == n)
    {
        if (j != k)
            ++sum;
        return;
    }
    if (k == 0)
    {
        foo(i + 1, j, 1);
        foo(i + 1, j, 2);
    }
    else if (k == 1)
    {
        foo(i + 1, j, 0);
        foo(i + 1, j, 2);
    }
    else
    {
        foo(i + 1, j, 0);
        foo(i + 1, j, 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n)
    {
        sum = 0;
        if (n == 1)
        {
            cout << 3 << endl;
            continue;
        }

        foo(1, 0, 0);
        foo(1, 1, 1);
        foo(1, 2, 2);
        cout << sum << endl;
    }

    return 0;
}