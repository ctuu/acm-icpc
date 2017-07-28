#include <bits/stdc++.h>
using namespace std;
class po
{
  public:
    int x, y;
    po() = default;
    po(int a, int b)
    {
        this->x = a;
        this->y = b;
    }
    bool operator<(class po const &b) const
    {
        if (x == b.x)
            return y < b.y;
        else
            return x < b.x;
    }
    bool operator==(class po const &b) const
    {
        if (x == b.x && y == b.y)
            return true;
        return false;
    }
    bool operator!=(class po const &b) const
    {
        if (x == b.x && y == b.y)
            return false;
        return true;
    }
    friend istream &operator>>(istream &is, po &item)
    {
        is >> item.x >> item.y;
        if (is)
            ;
        else
            item = po();
        return is;
    }
    friend ostream &operator<<(ostream &os, const po &item)
    {
        os << "x: " << item.x << " y: " << item.y << endl;
        return os;
    }
    void poly(class po const &a, class po const &b, bool fos)
    {
        if (fos == false)
        {
            this->y = a.y + b.x - a.x;
            if (a.x >= b.x)
                this->x = a.x + a.y - b.y;
            else
                this->x = a.x + b.y - a.y;
        }
        else
        {
            this->y = b.y + b.x - a.x;
            if (a.x >= b.x)
                this->x = b.x + a.y - b.y;
            else
                this->x = b.x + b.y - a.y;
        }
    }
};

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    int n, ans;
    set<po> oc;
    while (cin >> n)
    {
        ans = 0;
        oc.clear();
        for (int i = 0; i < n; ++i)
        {
            po temp;
            cin >> temp;
            oc.insert(temp);
        }

        // for (auto it = oc.cbegin(); it != oc.cend(); ++it)
        //     cout << *it;
        for (auto i = oc.cbegin(); i != oc.cend(); ++i)
            for (auto j = i; j != oc.cend(); ++j)
            {
                if (i == j)
                    continue;
                po pc, pd;
                bool ti = 1;
                if (i->x < j->x && i->y >= j->y || i->x >= j->x && i->y > j->y)
                {
                    pc.poly(*j, *i, false);
                    pd.poly(*j, *i, true);
                    ti = 0;
                }
                else
                {
                    pc.poly(*i, *j, false);
                    pd.poly(*i, *j, true);
                }
                if (oc.count(pc) && oc.count(pd))
                {
                    if (ti)
                        cout << *i << *j;
                    else
                        cout << "!" << *j << *i;
                    cout << pc << pd << endl;
                    ++ans;
                }
            }
        cout << ans << endl;
    }
    return 0;
}