#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<string> vc;
    for(int i = 0; i < n; ++i)
    {
        string tmp;
        cin >> tmp;
        vc.push_back(tmp);
    }

    sort(vc.begin(), vc.end(),[](string &a, string &b){
        return a.size() < b.size();});

    for (int i = 1; i < n; ++i)
        if (vc[i].find(vc[i - 1]) == string::npos)
        {
            cout << "NO" << endl;
            return 0;
        }
    

    cout << "YES" << endl;
    for (auto i : vc)
        cout << i << endl;
    return 0;
}