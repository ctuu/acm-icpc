#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (n == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    ++n;
    if (n % 2)
        cout << n << endl;
    else
        cout << n / 2 << endl;
    return 0;
}