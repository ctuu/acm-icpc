#include <bits/stdc++.h>
using namespace std;
struct lrs {
    string cn;
    string en;
};
bool comp(lrs a, lrs b);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<lrs> word;
    int i;
    cin >> i;
    word.resize(i);
    for (auto &c:word)
        cin >> c.cn >> c.en;
    sort(word.begin(), word.end(),comp);
    cout << endl << "Result" << endl;
    for (auto c:word)
    cout << setw(6) << fixed << c.cn << " " << c.en << endl;
    return 0;
}
bool comp(lrs a, lrs b)
{
    if (a.en <= b.en)
        return 1;
    return 0;
}
