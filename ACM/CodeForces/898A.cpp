#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    if (n % 10 > 5)
        cout << n + (10 - n % 10) << endl;
    else
        cout << n - n % 10 << endl;
    return 0;
}