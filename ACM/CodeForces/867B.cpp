#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if (n > 1)
    {
    cout << (n - 1) * 2<<" 2" << endl;
    cout << "1 2";
    }
    else
    cout << "1 1\n1";
    return 0;
}