#include <iostream>
#include <algorithm>
#include <array>
#include <set>
#include <vector>
#include <string>
using namespace std;
int main()
{
    double k = 0.5, j = 0.0, f = 1;
    for (int i = 0; i < 100; ++i)
    {
        f *= k;
        j += f;
    }
    cout << j;
    return 0;
}