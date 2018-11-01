#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, l;
    cin >> n >> m >> k >> l;
    if (n - k < m || n - k < l)
    {
        cout << "-1" << endl;
        return 0;
    }
    cout << ((k+l)/m + ((k+l)%m?1:0)) << endl;
    return 0;
}