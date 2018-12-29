#include <iostream>
#include <array>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    array<bool, 10> a;
    a.fill(0);
    for (int i = 1; i < 10; ++i)
        for (int j = 1; j < 10; ++j)
            for (int k = 1; k < 10; ++k)
            {
                if (i == j || j == k || i == k)
                    continue;
                a.fill(0);
                a[i] = a[j] = a[k] = 1;
                auto fc = [&](int x) -> bool {
                    while (x > 0)
                    {
                        int t = x % 10;
                        if (a[t] || t == 0)
                            return 0;
                        a[t] = 1;
                        x /= 10;
                    }
                    return 1;
                };
                if (fc((i * 100 + j * 10 + k) * 2) && fc((i * 100 + j * 10 + k) * 3))
                    cout << (i * 100 + j * 10 + k) << ' ' << (i * 100 + j * 10 + k) * 2 << ' ' << (i * 100 + j * 10 + k) * 3 << '\n';
            }
    return 0;
}