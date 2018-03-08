#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
array<int, 1000002> ar;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string n;
    ar.fill(0);
    for (int i = 1; i < 1000001; ++i)
    {
        ar[i] = ar[i - 1];
        n = to_string(i);
        bool flag = 0;
        for (auto i : n)
            if (i == '4')
            {
                flag = 1;
                break;
            }
        int tmp = n.size();
        tmp -= 3;
        if (tmp >= 0)
            for (int i = 0; i <= tmp; ++i)
                if (n[i] == '2' && n[i + 1] == '3' && n[i + 2] == '3')
                {
                    flag = 1;
                    break;
                }
        if (flag)
            continue;
        ++ar[i];
    }
    int a, b;
    while (cin >> a >> b)
        cout << ar[b] - ar[a - 1] << endl;

    return 0;
}