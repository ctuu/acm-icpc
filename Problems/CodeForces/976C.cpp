#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Nd
{
    pair<int, int> p;
    int id;
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Nd> vc;
    for (int i = 0; i < n; ++i)
    {
        pair<int, int> tp;
        cin >> tp.first >> tp.second;
        vc.push_back({tp, i + 1});
    }
    sort(vc.begin(), vc.end(), [](Nd a, Nd b) {
        if (a.p.first == b.p.first)
            return a.p.second < b.p.second;
        return a.p.first < b.p.first;
    });
    for (int i = 1; i < n; ++i)
    {
        if (vc[i].p.first == vc[i - 1].p.first)
        {
            cout << vc[i-1].id << " " << vc[i].id << endl;
            return 0;
        }
        if (vc[i].p.second <= vc[i - 1].p.second)
        {
            cout << vc[i].id << " " << vc[i - 1].id << endl;
            return 0;
        }
    }
    cout << "-1 -1" << endl;
    return 0;
}