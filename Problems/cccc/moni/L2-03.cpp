#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int N = 10000;
array<int, N> p, ts, rks;
array<double, N> mj;
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
bool cmp(int a, int b)
{
    double sa = mj[a] / rks[a];
    double sb = mj[b] / rks[b];
    if (sa == sb)
        return a < b;
    return sa > sb;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < N; ++i)
        p[i] = i;
    ts.fill(0);
    rks.fill(0);
    mj.fill(0.0);
    int n, id;
    set<int> pn;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int f, m, k, ch;
        cin >> id >> f >> m;
        pn.insert(id);
        int a = f;
        int b = m;
        int c = id;
        if (f != -1)
        {
            c = find(c);
            a = find(a);
            if (a < c)
                p[c] = a;
            else
                p[a] = c;
            pn.insert(f);
        }
        if (m != -1)
        {
            c = find(c);
            b = find(b);
            if (b < c)
                p[c] = b;
            else
                p[b] = c;
            pn.insert(m);
        }
        if (f != -1 && m != -1)
        {
            a = find(a);
            b = find(b);
            if (a < b)
                p[b] = a;
            else
                p[a] = b;
        }
        cin >> k;
        for (int j = 0; j < k; ++j)
        {
            cin >> ch;
            int d = find(ch);
            c = find(c);
            if (c < d)
                p[d] = c;
            else
                p[c] = d;
            pn.insert(ch);
        }
        cin >> ts[id] >> mj[id];
    }
    set<int> ns;
    for (auto i : pn)
    {
        int nid = find(i);
        ns.insert(nid);
        if (nid != i)
        {
            mj[nid] += mj[i];
            ts[nid] += ts[i];
        }
        rks[nid]++;
    }
    vector<int> nv;
    for (auto i : ns)
        nv.push_back(i);
    sort(nv.begin(), nv.end(), cmp);
    cout << nv.size() << endl;
    for (auto i : nv)
        cout << fixed << setw(4) << setfill('0') << i << " " <<rks[i] <<" " <<setprecision(3) << 1.0 * ts[i] / rks[i] << " " << mj[i] / rks[i] << endl;
    return 0;
}