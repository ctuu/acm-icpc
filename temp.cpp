#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#define MA 18
#define MB 30000
using namespace std;
int a[MA] = {0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584};
bool b[MB] = {0};
void add(int s, int l);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    add(0, 7);
    for (int i = 0; i < 20000; ++i)
        if (!b[i])
        {
            cout << i << " ";
            break;
        }
    return 0;
}

void add(int s, int l)
{
    if (!l)
    {
        b[s] = 1;
        return;
    }
    for (int i = 0; i < MA; ++i)
        add(s + a[i], l - 1);
}