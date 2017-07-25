#include <iostream>
#include <array>
using namespace std;
int main()
{
    array<int, 10> ti;
    int to = 0;
    for (auto &i: ti)
    {
        cin >> i;
        to += i;
    }
    for (int i = 1; i < 10; ++i)
        if (ti[i])
        {
            --ti[i];
            cout << i;
            --to;
            break;
        }
        
    while (to--)
    {
        for (int i = 0; i <10; ++i)
            if (ti[i])
            {
                --ti[i];
                cout << i;
                break;
            }
    }
    return 0;

}