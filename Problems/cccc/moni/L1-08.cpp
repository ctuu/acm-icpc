#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int exa[7]{0, 0, 24, 0, 24, 0, 24};
int dd[7]{0, 1, 1, 2, 2, 3, 3};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int d, h, m;
        char ch;
        cin >> d >> h >> ch >> m;
        if (d != 0)
        {
            int am = ((h + exa[d]) * 60 + m) / 2;
            h = am / 60;
            m = am - h * 60;
        }
        cout << dd[d] << " " << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0') << m << endl;
    }

    return 0;
}