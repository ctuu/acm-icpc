#include <iostream>
#include <cmath>
#include <list>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long t, s = 0, ans = 0;
    cin >> n >> t;
    list<int> a;
    a.resize(n);
    for (auto &i : a)
    {
        cin >> i;
        s += i;
    }
    while (!a.empty())
    {
        ans += floor(t / s) * a.size();
        t -= floor(t / s) * s;
        for(auto i = a.begin(); i != a.end(); ++i)
        {
            if(t < *i)
            {
                s -= *i;
                a.erase(i--);
                continue;
            }
            t -= *i;
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}