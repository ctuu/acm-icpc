#include <bits/stdc++.h>
#define SHIFT 100
using namespace std;
class po
{
  private:
    int x, y;

  public:
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
    int rx()
    {
        return x;
    }
    int ry()
    {
        return y;
    }
    bool poly(class po const &a, class po const &b, bool fos)
    {
        if (fos == false)
        {
            this->y = a.y + b.x - a.x;
            if (a.y != b.y)
                this->x = a.x + a.y - b.y;
            else
                this->x = a.x + b.y - a.y;
        }
        else
        {
            this->y = b.y + b.x - a.x;
            if (a.y != b.y)
                this->x = b.x + a.y - b.y;
            else
                this->x = b.x + b.y - a.y;
        }
        if (this->x < 0 || this->y < 0 || this->x > 200 || this->y > 200)
            return false;
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, ans;
    array<array<bool, 602>, 602> opo;
    array<po, 500> oc;
    while (cin >> n)
    {
        ans = 0;
        for (auto &i : opo)
            i.fill(false);
        for (int i = 0; i < n; ++i)
        {
            int a, b;
            cin >> a >> b;
            po te = po(a + SHIFT, b + SHIFT);
            oc[i] = te;
            opo[a + SHIFT][b + SHIFT] = true;
        }
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
            {
                po pc, pd;
                bool ti = 1;
                if (oc[i].rx() < oc[j].rx() && oc[i].ry() >= oc[j].ry() || oc[i].rx() >= oc[j].rx() && oc[j].ry() > oc[j].ry())
                {
                    if (!pc.poly(oc[j], oc[i], false) || !pd.poly(oc[j], oc[i], true))
                        continue;
                    ti = 0;
                }
                else
                {
                    if (!pc.poly(oc[i], oc[j], false) || !pd.poly(oc[i], oc[j], true))
                    continue;
                }
                // cout << oc[i] << oc[j] << pc << pd << endl;
                if (opo[pc.rx()][pc.ry()] && opo[pd.rx()][pd.ry()])
                    ++ans;
            }
        cout << ans / 2 << endl;
    }
    return 0;
}