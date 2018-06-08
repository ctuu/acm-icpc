#include <iostream>
#include <array>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    array<bool, 1003> bl;
    bl.fill(0);
    vector<int> vc;
    for(int i = 1; i <= n; ++i)
    {
        int k;
        cin >> k;
        if(!bl[k])
            vc.push_back(i);
        bl[k] = 1;
    }
    if(vc.size() < m)
        cout << "NO"<<endl;
    
    else
    {
        cout <<"YES"<<endl;
        for(int i = 0; i < m; ++i)
            cout << vc[i] <<" ";
    }
    return 0;
}