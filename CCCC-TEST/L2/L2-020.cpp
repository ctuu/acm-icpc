#include <bits/stdc++.h>
using namespace std;
void dfs(int i, int le);
vector<vector<int>> lj;
vector<int> level, power;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    double z, r;
    cin >> n >> z >> r;
    lj.resize(n);
    level.resize(n);
    power.resize(n);
    fill(level.begin(), level.end(),0);
    vector<int> dedao;
    for (int i = 0; i < n ; ++i)
    {
        int j;
        cin >> j;
        if (j > 0)
            while (j--)
            {
                int k;
                cin >> k;
                lj[i].push_back(k);
            }
        else
            {
            dedao.push_back(i);
            cin >> power[i];

            }
    }
    dfs(0, 0);
    double sum = 0;
//    for (auto i:dedao)
//        cout << i << " " << level[i] << endl;
    for (auto i:dedao)
        {
            double a = 0;
            a += z  * pow(1-r/100, level[i]) * power[i];
            sum += a;
        }
    cout <<  (long long) sum;
    return 0;
}
void dfs(int i, int le)
{
    if (!lj[i].empty())
    {
        for (auto k:lj[i])
        {
            level[k] = le+1;
            dfs(k, level[k]);
        }
    }
}
