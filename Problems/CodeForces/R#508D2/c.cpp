#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a, b;
    a.resize(n);
    b.resize(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    int ba = 0, bb = 0;
    long long sa = 0, sb = 0;
    while (ba < n || bb < n)
    {
        if (ba <= n)
        {
            if (((ba < n && a[ba] <= b[bb]) || ba == n) && bb < n)
            {
                // cout << "A rm " << b[bb] << endl;
                bb++;
            }
            else if(ba < n)
            {
                // cout << "A add " << a[ba] << endl;
                sa += a[ba];
                ba++;
            }
        }
        if (bb <= n)
        {
            if (((bb < n && b[bb] <= a[ba]) || bb == n) && ba < n)
            {
                // cout << "B rm " << a[ba] << endl;
                ba++;
            }
            else if(bb < n)
            {
                // cout << "B add " << b[bb] << endl;
                sb += b[bb];
                bb++;
            }
        }
    }
    cout << sa - sb << endl;
    return 0;
}