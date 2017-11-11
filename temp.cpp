#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    int fr, to, di;
    Edge() = default;
    Edge(int fr, int to, int di) : fr(fr), to(to), di(di) {}
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<Edge> k;
    k.resize(4);
    Edge j = Edge(1, 2, 3);
    return 0;
}