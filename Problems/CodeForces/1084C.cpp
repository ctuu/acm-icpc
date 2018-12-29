#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    s = s + "b";
    long long sum = 1, ct = 1;
    for (auto i : s)
    {
        if (i == 'a')
            ++ct;
        else if (i == 'b')
        {
            sum = (sum * ct) % MOD;
            ct = 1;
        }
    }
    cout << --sum << endl;
    return 0;
}