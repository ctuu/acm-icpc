#include <iostream>
#include <algorithm>
#include <array>
#include <set>
#define MN 500
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
array<vector<po>, 27> ar;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    set<int> al;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            char tmp;
            cin >> tmp;
            ar[tmp - 'a'].push_back(po(i, j));
            al.insert(tmp - 'a');
        }
    int ans = 0;
    for (auto ea: al)
    {
        array<array<bool, 601>, 601> opo;
        array<po, 501> oc;
    }
    return 0;
}
