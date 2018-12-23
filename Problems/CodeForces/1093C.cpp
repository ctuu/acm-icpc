#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> b;
    b.resize(n / 2);
    for (auto &i : b)
        cin >> i;
    deque<long long> q;
    q.push_front(*b.crbegin() / 2);
    q.push_back(*b.crbegin() - *b.crbegin() / 2);
    for (auto i = b.crbegin() + 1; i < b.crend(); ++i)
    {
        long long qf = *q.begin(), qe = *q.rbegin();
        long long f = *i, e = 0;
        if (f > qf)
        {
            e += f - qf;
            f = qf;
        }
        if (e < qe)
        {
            f -= qe - e;
            e = qe;
        }
        if (f > e)
            swap(f, e);
        q.push_front(f);
        q.push_back(e);
    }
    for (auto i : q)
        cout << i << ' ';
    cout << endl;
    return 0;
}