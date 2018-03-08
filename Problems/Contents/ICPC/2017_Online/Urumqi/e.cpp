#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a[24] = {
        0, 1, 8, 49, 288, 1681, 9800, 57121, 332928, 1940449,
        11309768, 65918161, 384199200, 2239277041,
        13051463048, 76069501249, 443365544448,
        2584123765441, 15061377048200, 87784138523761,
        511643454094368, 2982076586042449,
        17380816062160328, 101302819786919521};
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        long long n;
        cin >> n;
        cout << "Case #" << i << ": ";
        for (int j = 0; j < 24; ++j)
            if (a[j] >= n)
            {
                cout << a[j] << endl;
                break;
            }
    }
    return 0;
}