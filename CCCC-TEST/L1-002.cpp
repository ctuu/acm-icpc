// 1 3*2 7 10 17 14 31
// 2n-1
#include <iostream>
int N;
void draw(int n, char ch);
int main()
{
    int i, n;
    char ch;
    std::cin >> n >> ch;
    i = 1;
    --n;
    if (n >= 6)
        for (i = 2; n > 4 * i - 2; ++i)
            n -= 4 * i - 2;
    --i;
    N = i;
    if (i > 1)
        draw(i, ch);
    else
        std::cout << ch << '\n';

    if (n > 0)
        std::cout << n;
    return 0;
}
void draw(int n, char ch)
{
    if (n < 1)
        return;
    int i;
    if (n == 1)
    {
        for (i = 0; i < 2 * (N - n) - 1; ++i)
            std::cout << " ";
        std::cout << ch << '\n';
        return;
    }
    for (i = 0; i < 2 * (N - n) - 1; ++i)
        std::cout << " ";
    for (i = 0; i < 2 * n - 1; ++i)
        std::cout << ch;
    std::cout << '\n';
    draw(n - 1, ch);
    for (i = 0; i < 2 * (N - n) - 1; ++i)
        std::cout << " ";
    for (i = 0; i < 2 * n - 1; ++i)
        std::cout << ch;
    std::cout << '\n';
}