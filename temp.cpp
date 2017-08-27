#include <iostream>
#include <algorithm>
#include <array>
#include <iomanip>
#include <set>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    array<int, 10> ar;
    for (int i = 0; i < 10; ++i)
        ar[i] = 2 * i + 1;
    auto i = upper_bound(ar.begin(), ar.end(), 123, [](int a, int b) {
        return a < b;
    });
    cout << *(i - 1);
    return 0;
}