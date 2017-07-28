#include <bits/stdc++.h>
using namespace std;
class po
{
  private:
    int x, y;

  public:
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
        is >>item.x >> item.y;
        if (is)
        ;
        else
            item = po();
        return is;
    }
    friend ostream &operator << (ostream &os, const po &item)
    {
        os << "x: " << item.x << " y: " << item.y << endl;
        return os;
    }
    // bool issq(class po const &a)
    // {
    //     po pc, pd;
    //     return true;
    //     return false;
    // }
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
        for (auto it = oc.begin(); it != oc.end(); ++it)
            cout << *it;
        // for (set<po>::iterator it = oc.begin(); it != oc.end(); ++it)
        // for (auto i : oc)
        // {
        //     for (auto j : oc)
        //         if (i == j)
        //             continue;
        //         else
        //             cout << "2";
        // }
    }
    return 0;
}