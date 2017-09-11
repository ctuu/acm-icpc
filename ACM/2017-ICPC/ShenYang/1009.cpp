#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 239;
    n += 512;
    for (int i = 0; i < 9; ++i)
    {
        int j = n & 1;
        n >>= 1;
        if (j)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}