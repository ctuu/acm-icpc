#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h, m;
    char ch;
    cin >> h >> ch >> m;
    if (h < 12 || (h == 12 && m == 0))
    {
        cout << "Only " << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0') << m << ".  Too early to Dang." << endl;
        return 0;
    }
    h -= 12;
    if (m)
        h++;
    while (h--)
        cout << "Dang";

    return 0;
}