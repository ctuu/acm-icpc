//Author:.firstiaowuga
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <map>
#include <bitset>
#define mem(s,ch) memset(s,ch,sizeof(s))
#define da cout<<da<<endl
const long long N=500+10;
using namespace std;
int n;
set<pair<int,int>>qu;
// int pic[250][250];
pair<int,int>s[N];
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    else return a.first<b.first;
}
int main()
{
    while (cin >> n)
    {
        qu.clear();
        long long ct = 0;
        // mem(pic, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> s[i].first >> s[i].second;
            qu.insert(s[i]);
            // pic[s[i].first + 100][s[i].second + 100] = 1;
        }
        //sort(s,s+n,cmp);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                pair<int, int> t1, t2;
                int f1 = 1, f2 = 1;
                int mod = 0;
                if (s[i].first >= s[j].first && s[i].second <= s[j].second)
                {
                    mod = 1;
                    t1.first = s[i].second - s[j].second + s[i].first;
                    t1.second = s[i].first - s[j].first + s[i].second;
                    t2.first = s[i].second - s[j].second + s[j].first;
                    t2.second = s[i].first - s[j].first + s[j].second;
                }
                else if (s[i].first < s[j].first && s[i].second > s[j].second)
                {
                    mod = 2;
                    t1.first = s[j].second - s[i].second + s[j].first;
                    t1.second = s[j].first - s[i].first + s[j].second;
                    t2.first = s[j].second - s[i].second + s[i].first;
                    t2.second = s[j].first - s[i].first + s[i].second;
                }
                else if (s[i].first <= s[j].first && s[i].second <= s[j].second)
                {
                    mod = 3;
                    t1.first = s[i].second - s[j].second + s[i].first;
                    t1.second = s[j].first - s[i].first + s[i].second;
                    t2.first = s[i].second - s[j].second + s[j].first;
                    t2.second = s[j].first - s[i].first + s[j].second;
                }
                else if (s[i].first > s[j].first && s[i].second > s[j].second)
                {
                    mod = 4;
                    t1.first = s[j].second - s[i].second + s[j].first;
                    t1.second = s[i].first - s[j].first + s[j].second;
                    t2.first = s[j].second - s[i].second + s[i].first;
                    t2.second = s[i].first - s[j].first + s[i].second;
                }
                else
                continue;
                if (!qu.count(t1))
                    f1 = 0;
                if (!qu.count(t2))
                        f2 = 0;
                if (f1 && f2)
                {
                    ct++;
                    cout << "si " << s[i].first << " " << s[i].second << endl;
                    cout << "sj " << s[j].first << " " << s[j].second << endl;
                    cout << "t1 " << t1.first << " " << t1.second << endl;
                    cout << "t2 " << t2.first << " " << t2.second << endl;
                    cout << mod << endl << endl;
                }
            }
        cout << ct / 2 << endl;
    }
    return 0;
}