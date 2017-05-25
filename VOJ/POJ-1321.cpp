#include <iostream>
#include <string>

using namespace std;

int pan[8][8] = {0};
bool jc[8] = {0};
int n, k, ti;
void find(int x, int cur);

int main()
{
    string cur;
    while (cin >> n >> k && n != -1 && k != -1)
    {
        ti = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> cur;
            for (int j = 0; j < n; ++j)
                if (cur[j] == '.')
                    pan[i][j] = 0;
                else
                    pan[i][j] = 1;
        }
        // for (auto i: pan)
        // {
        //     for (auto j: i)
        //     cout << j << " ";
        //     cout << endl;
        // }
        find(0, 0);
        cout << ti << endl;
    }
    return 0;
}

void find(int x, int cur)
{
    int a, b;
    if (cur == k)
    {
        ++ti;
        return;
    }
    if (x < n)
    {
        for (int i = 0; i < n; ++i)
        {
            if (!jc[i] && pan[x][i])
            {
                jc[i] = 1;
                find (x + 1, cur + 1);
                jc[i] = 0;
            }
        }
        find (x + 1, cur);
    }
    else
        return;
}
