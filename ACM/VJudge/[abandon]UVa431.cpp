#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <array>
#include <string>
#include <vector>
#define MT 260
using namespace std;
struct no
{
    int s, t;
    string le;
    no() = default;
    no(int a, int b, string c)
    {
        this->s = a;
        this->t = b;
        this->le = c;
    }
};
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    int t;
    cin >> t;
    cin.get();
    while (t--)
    {
        int tot;
        cin >> tot;
        cin.get();
        vector<no> va;
        string s;
        stringstream te;
        while (getline(cin, s))
        {
            if (s.size() == 0)
                break;
            te.str(s);
            int a, b;
            te >> a >> b;
            getline(te, s);
            va.push_back(no(a, b, s));
            te.clear();
        }
        sort(va.begin(), va.end(), [](no a, no b) { if (a.t != b.t)
                return a.t < b.t;
            else if (a.s != b.s)
                return a.s > b.s;
            else
            return a.le < b.le; });
        array<int, MT> dp;
        array<array<bool, MT>, MT> p;
        dp.fill(-1);
        for (auto &i : p)
        i.fill(false);
        int ct = va.size();
        for (int i = 0; i < ct; ++i)
            for (int j = tot; j >= va[i].t; --j)
                if (dp[j] < dp[j - va[i].t] + va[i].s)
                {
                    dp[j] = dp[j - va[i].t] + va[i].s;
                    p[i][j] = true;
                }
        int tsc = 0;
        vector<no> li;
        for (int i = ct - 1, j = tot; i >= 0; --i)
            if (p[i][j])
            {
                li.push_back(va[i]);
                j -= va[i].t;
                tsc += va[i].s;
            }
        sort(li.begin(), li.end(), [](no a, no b) {if (a.t != b.t)
                return a.t < b.t;
            else if (a.s != b.s)
                return a.s > b.s;
            else
            return a.le < b.le; });
        if (li.size())
        {
            cout << "Score  Time  Description\n-----  ----  -----------\n";
            int tst = 0;
            for (auto i : li)
            {
                printf("%3d%7d  ", i.s, i.t);
                cout << i.le << endl;
                tst += i.t;
            }
            printf("\nTotal score: %d points\n Total time: %d hours", tsc, tst);
        }
        else
            printf("There is not enough time to present any evidence. Drop the charges.");
        puts(t ? "\n" : "");
    }
    return 0;
}