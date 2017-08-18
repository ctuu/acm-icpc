#include <iostream>
#include <algorithm>
#include <array>
#include <iomanip>
#include <set>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int a = 1; a <= 4; ++a)
    {
        for (int b = 1; b < 5; ++b)
        {
            for (int c = 1; c < 5; ++c)
            {
                for (int d = 1; d < 5; ++d)
                    cout << a << b << c << d << ",";
                cout << endl;
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}