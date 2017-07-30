#include <bits/stdc++.h>
#define N 20000
#define V 20000
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n = 0, v, sum = 0;
        array<int, N + 1> mar;
        string num;
        getline(cin, num);
        istringstream record(num);
        while (record)
        {
            record >> mar[n];
            sum += mar[n];
            ++n;
        }
        cout << n << endl;
        array<int, V + 1> dp;
        dp.fill(0);
    }
    return 0;
}