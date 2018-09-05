#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    int la = a.size();
    int lb = b.size();
    int c = 0;
    for(c = 0; c < min(la, lb); ++c)
        if(*(a.rbegin() + c) != *(b.rbegin() + c))
            break;
    int n =  la - c + lb - c;
    cout << n << endl;
    return 0;
}