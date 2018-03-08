#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    array<string, 5> en{"Danil", "Olya", "Slava", "Ann", "Nikita"};
    string len;
    cin >> len;
    int exist = 0;
    for (int i = 0; i < 5; ++i)
        if (len.find(en[i], 0) != string::npos)
            exist++;
    if (exist != 1)
    {
        cout << "NO";
        return 0;
    }
    else
        for (int i = 0; i < 5; ++i)
            if (len.find(en[i], 0) != string::npos && len.find(en[i], 0) == len.rfind(en[i]))
            {
                cout << "YES";
                return 0;
            }
    cout << "NO";
    return 0;
}