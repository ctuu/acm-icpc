#include <iostream>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <array>
#include <string>
#include <vector>
#define PII pair<int, int>
using namespace std;
vector<PII> item;
int memo[200][300];
bool taken[200][300];

int REC(int p, int w)
{
    if (p == item.size() || w == 0)
        return 0;
    if (~memo[p][w])
        return memo[p][w];
    int a, b;
    a = b = 0;
    if (item[p].second <= w)
        a = REC(p + 1, w - item[p].second) + item[p].first;
    b = REC(p + 1, w);
    taken[p][w] = a > b;
    return memo[p][w] = max(a, b);
}

struct adu
{
    string s;
    int time, val;
    bool friend operator<(const adu &a, const adu &b) { return a.time < b.time; };
} tmpadu;

int main()
{
    ios_base::sync_with_stdio(0);
    // cin.tie(0);
    int tc, W, val, w;
    string line, a;
    stringstream foo;
    vector<string> sen;
    cin >> tc;
    getline(cin, line);
    getline(cin, line);
    while (tc--)
    {
        sen.clear();
        item.clear();
        memset(memo, -1, sizeof memo);
        memset(taken, 0, sizeof taken);
        cin >> W;
        getline(cin, line);
        while (getline(cin, line) && line != "")
        {
            foo.clear(), foo.str(line);
            foo >> val >> w;
            getline(foo, a);
            a.erase(a.begin());
            item.push_back(make_pair(val, w));
            sen.push_back(a);
        }
        int score = REC(0, W), total_time = 0;
        int p = 0;
        if (score == 0)
        {
            cout << "There is not enough time to present any evidence. Drop the charges." << endl;
            if (tc)
                cout << endl;
            continue;
        }
        vector<adu> res;
        while (p < item.size())
        {
            if (taken[p][W])
            {
                tmpadu.s = sen[p];
                tmpadu.val = item[p].first;
                tmpadu.time = item[p].second;
                total_time += tmpadu.time;
                W -= tmpadu.time;
                res.push_back(tmpadu);
            }
            p++;
        }
        sort(res.begin(), res.end());
        cout << "Score  Time  Description\n";
        cout << "-----  ----  -----------\n";
        for (int i = 0; i < res.size(); i++)
            cout << setw(3) << res[i].val << "    " << setw(3) << res[i].time << "   " << res[i].s << endl;
        cout << endl;
        cout << "Total score: " << score << " points\n";
        cout << " Total time: " << total_time << "  hours\n";
        if (tc)
            cout << endl;
    }
    return 0;
}