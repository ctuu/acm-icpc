#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int s, v1, v2, t1, t2, an1, an2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    an1 = s * v1 + 2 * t1;
    an2 = s * v2 + 2 * t2;
    if (an1 == an2)
        cout << "Friendship";
    else if (an1 < an2)
        cout << "First";
    else
        cout << "Second";
    return 0;
}