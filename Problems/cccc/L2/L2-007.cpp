#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
const int N = 10003;
array<int, N> p;
map<int, int> nums;
struct Mem
{
    int f;
    double mj;
};
array<Mem, N> mp;
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < N; ++i)
        p[i] = i;
    set<int> ids;
    int n, id, fid, mid, k, m;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> id >> fid >> mid;
        ids.insert(id);
        if (fid != -1)
        {
            int a = find(id), b = find(fid);
            if (a > b)
                p[a] = b;
            else
                p[b] = a;
            ids.insert(fid);
        }
        if (mid != -1)
        {
            int a = find(id), b = find(mid);
            if (a > b)
                p[a] = b;
            else
                p[b] = a;
            ids.insert(mid);
        }
        if (fid != -1 && mid != -1)
        {
            int a = find(fid), b = find(mid);
            if (a > b)
                p[a] = b;
            else
                p[b] = a;
        }
        cin >> k;
        for (int j = 0; j < k; ++j)
        {
            cin >> m;
            int a = find(id), b = find(m);
            if (a > b)
                p[a] = b;
            else
                p[b] = a;
            ids.insert(m);
        }
        int f;
        double z;
        cin >> f >> z;
        mp[id] = Mem{f, z};
    }
    set<int> aum;
    for (auto i : ids)
    {
        int tmp = find(i);
        nums[tmp]++;
        if (tmp != i)
        {
            mp[tmp].f += mp[i].f;
            mp[tmp].mj += mp[i].mj;
        }
        aum.insert(tmp);
        // cout << find(i) << " ";
    }
    cout << aum.size() << endl;
    vector<int> ve;
    for (auto i : aum)
        ve.push_back(i);
    sort(ve.begin(), ve.end(), [](int a, int b) {
        double c = mp[a].mj / nums[a];
        double d = mp[b].mj / nums[b];
        if(c == d)
            return a < b;
        else
        return c > d;
        ; });
    for (auto i : ve)
        cout << fixed << setw(4) << setfill('0') << i << " " << nums[i] << " " << setprecision(3) << (double)mp[i].f / nums[i] << " " << mp[i].mj / nums[i] << endl;
    return 0;
}