#include <bits/stdc++.h>
using namespace std;
int n;
array<int, 21> pren;
set<int> nu;
void calc (int i, int s);
int main()
{
    while (cin >> n)
    {
        nu.clear();
        for (int i = 0; i < n; ++i)
            cin >> pren[i];
        calc(0, 0);
        cout << nu.size() << endl;
    }
    return 0;
}
void calc (int i,int s)
{
    if (i >= n)
    {
        nu.insert(s);
        return;
    }
    int s1 = s + pren[i];
    int s2 = s - pren[i];
    calc(i + 1, s1);
    calc(i + 1, s2);
}