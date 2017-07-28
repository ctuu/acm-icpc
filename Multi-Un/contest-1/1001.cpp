#include <bits/stdc++.h>
#define LOG2 0.30102999566398119521373889472449
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 0, i;
    while (cin >> i)
    {
        n++;
        cout << "Case #" << n << ": " << (int) (i * LOG2) << endl;
    }
    return 0;
}