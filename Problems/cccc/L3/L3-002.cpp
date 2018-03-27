#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
const int N = 100005;
struct No
{
    int fa, key, lc, rc, level;
};
int stalv, mid;
array<No, N> tr;
void add(int c, int r)
{
    if (c <= tr[r].key)
    {
        if (tr[r].lc != -1)
            add(c, tr[r].lc);
        else
        {
            ++stalv;
            tr[r].lc = stalv;
            tr[stalv] = No{stalv - 1, c, -1, -1, stalv};
        }
    }
    else
    {
        if (tr[r].rc != -1)
            add(c, tr[r].rc);
        else
        {
            ++stalv;
            tr[r].rc = stalv;
            tr[stalv] = No{stalv - 1, c, -1, -1, stalv};
        }
    }
}
void del(int c)
{
    int fa = tr[c].fa;
    if (tr[fa].lc == c)
        tr[fa].lc = -1;
    if (tr[fa].rc == c)
        tr[fa].rc = -1;
}
void findb(int c)
{
    if (c == -1)
        return;
    if (tr[c].rc != -1 && tr[tr[c].rc].key > tr[mid].key)
    {
        int k = tr[c].rc;
        while (tr[k].lc != -1)
            k = tr[k].lc;
        mid = k;
    }
    else
    {
        if (tr[tr[c].fa].key > tr[mid].key)
            mid = tr[c].fa;
        else
            findb(tr[c].fa);
    }
}
void findl(int c)
{
    if (c == -1)
        return;
    if (tr[c].lc != -1 && tr[tr[c].lc].key <= tr[mid].key)
    {
        int k = tr[c].lc;
        while (tr[k].rc != -1)
            k = tr[k].rc;
        mid = k;
    }
    else
    {
        if (tr[tr[c].fa].key <= tr[mid].key)
            mid = tr[c].fa;
        else
            findb(tr[c].fa);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    stalv = 0;
    int n, t;
    cin >> n;
    string sl;
    for (int i = 0; i < n; ++i)
    {
        bool fl = 0;
        cin >> sl;
        if (sl == "Pop")
        {
            if (stalv > 0)
            {
                cout << tr[stalv].key << endl;
                del(stalv);
                stalv--;
                if (stalv % 2 == 0 && tr[stalv].key >= tr[mid].key)
                    findl(mid);
                else if (stalv % 2 == 1 && tr[stalv].key <= tr[mid].key)
                    findb(mid);
            }
            else
                fl = 1;
        }
        if (sl == "Push")
        {
            cin >> t;
            if (stalv == 0)
            {
                stalv++;
                tr[stalv] = No{-1, t, -1, -1, stalv};
                mid = stalv;
                continue;
            }
            add(t, 1);
            if (stalv % 2 == 1 && tr[stalv].key > tr[mid].key)
                findb(mid);
            else if (stalv % 2 == 0 && tr[stalv].key <= tr[mid].key)
                findl(mid);
        }
        if (sl == "PeekMedian")
        {
            if (stalv > 0)
                cout << tr[mid].key << endl;
            else
                fl = 1;
        }
        if (fl)
            cout << "Invalid" << endl;
    }
    return 0;
}