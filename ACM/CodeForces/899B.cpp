#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
array<int, 60> le = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
array<int, 36> nle = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
array<int, 30> ar;
bool coml(int n, int b)
{
    for (int i = b; i < b + n; ++i)
        if (ar[i - b] != le[i])
            return 0;
    return 1;
}
bool comnl(int n, int b)
{
    for (int i = b; i < b + n; ++i)
        if (ar[i - b] != nle[i])
            return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> ar[i];
    for (int i = 0; i < 60 - n; ++i)
        if (coml(n, i))
        {
            cout << "yes" << endl;
            return 0;
        }
    for (int i = 0; i < 36 - n; ++i)
        if (comnl(n, i))
        {
            cout << "yes" << endl;
            return 0;
        }
    cout << "no" << endl;
    return 0;
}