#include <bits/stdc++.h>
#define SHIFT 300
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
    int rx()
    {
        return x;
    }
    int ry()
    {
        return y;
    }
    void poly(class po const &a, class po const &b, bool fos)
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
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    array<array<bool, 601>, 601> opo;
    array<po, 501> oc;
    while (cin >> n)
    {
        int ans = 0;
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
                pc.poly(oc[j], oc[i], false);
                pd.poly(oc[j], oc[i], true);
                if (opo[pc.rx()][pc.ry()] && opo[pd.rx()][pd.ry()])
                    ++ans;
                pc.poly(oc[i], oc[j], false);
                pd.poly(oc[i], oc[j], true);
                if (opo[pc.rx()][pc.ry()] && opo[pd.rx()][pd.ry()])
                    ++ans;
            }
        cout << ans / 4 << endl;
    }
    return 0;
}