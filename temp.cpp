#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    array<int, 500000> ar;
    array<int, 300> br;
    for (int i = 0; i < 300; ++i)
        br[i] = i * 2;
    ar.fill(1);
    for (int i = 1; i < 300; ++i)
        for (int j = 0; j < 5000; ++j)
            ar[br[i] + j]++;
    for (int i = 1; i < 39; ++i)
        cout << ar[i] << " ";
}