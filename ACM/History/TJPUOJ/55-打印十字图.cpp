#include <bits/stdc++.h>
#define MNUM 121
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    array<array<char, MNUM>, MNUM> word;
    for (auto &k : word)
        k.fill('.');
    int n, rw, i;
    cin >> n;
    rw = 1 + 4 * 29;
    for (i = 0; i <= 29; ++i, rw -= 4)
    {
        int x = 2 * i;
        int y = (i + 1) * 2;
        for (int j = 0; j < rw; ++j, ++y)
            word[x][y] = '$';
        --y;
        ++x;
        word[x][y] = '$';
        ++x;
        word[x][y] = '$';
        ++y;
        word[x][y] = '$';
        ++y;
        word[x][y] = '$';
        for (int j = 0; j < rw; ++j, ++x)
            word[x][y] = '$';
        --x;
        --y;
        word[x][y] = '$';
        --y;
        word[x][y] = '$';
        ++x;
        word[x][y] = '$';
        ++x;
        word[x][y] = '$';
        for (int j = 0; j < rw; ++j, --y)
            word[x][y] = '$';
        ++y;
        --x;
        word[x][y] = '$';
        --x;
        word[x][y] = '$';
        --y;
        word[x][y] = '$';
        --y;
        word[x][y] = '$';
        for (int j = 0; j < rw; ++j, --x)
            word[x][y] = '$';
        ++x;
        ++y;
        word[x][y] = '$';
        ++y;
        word[x][y] = '$';
        --x;
        word[x][y] = '$';
        --x;
        word[x][y] = '$';
    }
    rw = 1 + 4 * n;
    int x = 57 - n * 2;
    int mx = x + rw + 4;
    int y = 57 - n * 2;
    int my = y + rw + 4;
    word[x + 1][y + 1] = '.';
    word[mx][y + 1] = '.';
    word[x + 1][my] = '.';
    word[mx][my] = '.';
    while (x++ < mx)
    {
        y = 57 - n * 2;
        my = y + rw + 4;
        while (y++ < my)
            cout << word[x][y];
        cout << endl;
    }
    return 0;
}
