#include <bits/stdc++.h>
using namespace std;
struct stu {
    string name;
    string id;
    int grade;
};
bool comp_stu(stu a, stu b);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector <stu> cu;
    cu.resize(n);
    for (auto &i: cu)
        cin >> i.name >> i.id >> i.grade;
    sort (cu.begin(), cu.end(), comp_stu);
    cout << cu[n - 1].name << " " << cu[n - 1].id << endl;
    cout << cu[0].name << " " << cu[0].id << endl;
    return 0;
}
bool comp_stu(stu a, stu b)
{
    return a.grade < b.grade;
}
