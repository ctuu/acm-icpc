#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long ax, ay, bx, by, cx, cy;
    long long dx, dy, ex, ey, fx, fy;
    long long lo, lt;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    if (ax == bx && ax == cx || ay == by && ay == cy)
    {
        cout << "No";
        return 0;
    }
    dx = bx - ax, dy = by - ay;
    ex = cx - ax, ey = cy - ay;
    fx = cx - bx, fy = cy - by;
    lo = (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
    lt = (cx - bx) * (cx - bx) + (cy - by) * (cy - by);
    // cout << lo << " " << lt << endl;
    if (dy / (double)dx == ey / (double)ex && dy / (double)dx == fy / (double)fx)
        cout << "No";
    else if (lo == lt)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}