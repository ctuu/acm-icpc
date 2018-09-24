#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using PII = pair<long long, long long>;
int main()
{
    int n;
    cin >> n;
    vector<PII> v;
    v.resize(n);
    for(auto &i: v)
        cin >> i.first >> i.second;
    sort(v.begin(), v.end(), [](PII &a, PII &b){
        return a.first + a.second > b.first + b.second;
    });
    cout << v[0].first + v[0].second << endl;
    return 0;
}