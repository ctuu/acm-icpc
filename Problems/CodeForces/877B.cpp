#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string len;
    cin >> len;
    vector<pair<int, int>> ar;
    int n = len.size();
    int i = 0;
    for (; i < n; ++i)
        if (len[i] == 'a')
            break;
    ar.push_back(pair<int, int>(1, 1));
    int ct = 0;
    for (i += 1; i < n; ++i)
    {
        if (len[i] != len[i - 1])
        {
            ar.push_back(pair<int, int>((ar[ct].first == 1) ? 0 : 1, 1));
            ++ct;
        }
        else
            ++ar[ct].second;
    }
    ct = ar.size();
    // for (auto i : ar)
    //     cout << i.first << " " << i.second << endl;
    long long mam = 0;
    for (int i = 0; i < ct; ++i)
    {
        if (ar[i].first == 1)
            continue;
        long long tmp = ar[i].second;
        int mj = 0;
        for (int j = 0; j < i; ++j)
            if (ar[j].first == 1)
                mj = max(mj, ar[j].second);
        tmp += mj;
        mj = 0;
        for (int j = i + 1; j < ct; ++j)
            if (ar[j].first == 1)
                mj = max(mj, ar[j].second);
        tmp += mj;
        mam = max(mam, tmp);
    }
    for (int i = 0; i < ct; ++i)
    {
        if (ar[i].first == 0)
            continue;
        long long tmp = ar[i].second;
        int mj = 0;
        for (int j = 0; j < i; ++j)
            if (ar[j].first == 0)
                mj = max(mj, ar[j].second);
        tmp += mj;
        mj = 0;
        for (int j = i + 1; j < ct; ++j)
            if (ar[j].first == 0)
                mj = max(mj, ar[j].second);
        tmp += mj;
        mam = max(mam, tmp);
    }
    cout << mam;
    return 0;
}