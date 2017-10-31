#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int fib[35];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= 31; i++)
        fib[i] = fib[i - 2] + fib[i - 1];
    for(int i = 0; i <= 31;++i)
        cout << fib[i] << " ";
    return 0;
}