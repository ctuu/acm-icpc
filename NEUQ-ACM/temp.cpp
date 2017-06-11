#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
 ios::sync_with_stdio(false);
 cin.tie(0);
    int T;
    int num[15];
    cin>>T;
    for(int i=1;i<=T;i++){
        int n;
        cin>>n;
        for(int j=0;j<10;j++) cin>>num[j];
        sort(num,num+10);
        cout<<i<<" "<<num[7]<<endl;
    }
 return 0;
}
