#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
struct Edge
{
    int from, to, dist;
    Edge(int u, int v, int d) : from(u), to(v), dist(d) {}
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Edge a = Edge(1,3,4);
    cout << a.from << " " << a.to << " " << a.dist<< endl;
    return 0;
}