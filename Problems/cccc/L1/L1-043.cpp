#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int ttoi(string c)
{
    return stoi(c.substr(0, 2)) * 60 + stoi(c.substr(3, 5));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    while (N--)
    {
        int bt = 0, tot = 0, id;
        char c;
        string str;
        array<bool, 1003> b;
        b.fill(0);
        array<int, 1003> tm;
        while (cin >> id >> c >> str && id)
            if (c == 'S')
            {
                b[id] = 1;
                tm[id] = ttoi(str);
            }
            else
            {
                if (!b[id])
                    continue;
                b[id] = 0;
                ++bt;
                tot += ttoi(str) - tm[id];
            }
        tot = bt == 0 ? 0 : 1.0 * tot / bt + 0.5;
        cout << bt << " " << tot << endl;
    }
    return 0;
}