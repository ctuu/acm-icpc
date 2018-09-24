#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a = 1;
    int b = 1;
    int c = n - a - b;
    if(c%3==0)
    {
        a++;
        c--;
    }
    cout << a << " " << b << " " << c << endl;
    return 0;
}