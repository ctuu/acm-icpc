#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    array<int, 9> a = {3, 4, 34, 1, 54, 7, 12, 45, 2};
    int N = 9;
    int h = 1;
    while (h < N / 3)
        h = 3 * h + 1;
    while (h >= 1)
    {
        for (int i = h; i < N; ++i)
            for (int j = i; j >= h && a[j] < a[j - h]; j -= h)
            {
                int k = a[j];
                a[j] = a[j - h];
                a[j - h] = k;
                for (auto i : a)
                cout << i << " ";
                cout << endl;
            }
        h /= 3;
    }
    for (auto i : a)
        cout << i << " ";
    return 0;
}