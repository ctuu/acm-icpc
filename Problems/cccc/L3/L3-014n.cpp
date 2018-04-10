#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
const int N = 1e5+7;
const int M = 1e5+7;
const int INF = 0x3f3f3f3f;
array<int, N> d;
array<int, M> pth;
struct Node {
    int d, u, id;
};
struct Edge {
    int fr, to ,di;
};
struct ptc {
    int fr, to, id;
};
using G = vector<vector<int>>;
using E = vector<Edge>;
void dijk(G &gr, E &edg, int s)
{
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    return 0;
}