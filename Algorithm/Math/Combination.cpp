#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
const int N = 52;
const int M = 52;
array<array<int, M>, N> com;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    com[1][0] = 1;
    for(int i = 1; i < M; ++i)
        for(int j = 1; j < N; ++j)
            com[j][i] = com[j-1][i-1] + com[j][i-1];
    cout << com[4][3] << endl;
    return 0;
}