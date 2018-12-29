#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, c = 0, sum = 0;
    for (int i = 0; sum >= 0 && i < 12; ++i)
    {
        c += 300;
        cin >> a;
        if (c < a)
            sum = -(i + 1);
        c -= a;
        sum += c - c % 100;
        c = c % 100;
    }
    cout << (sum > 0 ? c + sum * 1.2 : sum);
    return 0;
}