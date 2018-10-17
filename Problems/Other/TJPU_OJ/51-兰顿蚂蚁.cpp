#include <iostream>
bool map[101][101];
void antgo(int &x, int &y, int &s);
void move(int &x, int &y, int s);
void chan(int &s, bool i);
int main(void)
{
    int i, j, n, m, x, y, k;
    char s;
    std::cin >> m >> n;
    for (i = 0; i < m; ++i)
        for (j = 0; j < n; ++j)
            std::cin >> map[i][j];
    std::cin >> x >> y >> s >> k;
    if (s == 'U')
        i = 0;
    else if (s == 'R')
        i = 1;
    else if (s == 'D')
        i = 2;
    else if (s == 'L')
        i = 3;
    while (k--)
        antgo(x, y, i);
    std::cout << x << " " << y << std::endl;
    return 0;
}

void antgo(int &x, int &y, int &s)
{
    map[x][y] = !map[x][y];
    chan(s, !map[x][y]);
    move(x, y, s);
}
void move(int &x, int &y, int s)
{
    if (s == 0)
        --x;
    else if (s == 1)
        ++y;
    else if (s == 2)
        ++x;
    else
        --y;
}
void chan(int &s, bool i)
{
    if (i)
        ++s;
    else
        --s;
    if (s == 4)
        s = 0;
    if (s == -1)
        s = 3;
}