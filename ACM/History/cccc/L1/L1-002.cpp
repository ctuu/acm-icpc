#include <iostream>
int N;
char ch;
void draw(int n);
int main()
{
    int i, num;
    std::cin >> num >> ch;
    --num;
    for (i = 2; num >= 4 * i - 2; ++i)
        num -= 4 * i - 2;
    --i;
    N = i;
    draw(i);
    std::cout << num;
    return 0;
}

void draw(int n)
{
    int i;
    for (i = 0; i < N - n; ++i)
        std::cout << " ";
    for (i = 0; i < 2 * n - 1; ++i)
        std::cout << ch;
    std::cout << '\n';
    if (n == 1)
        return;
    draw(n - 1);
    for (i = 0; i < N - n; ++i)
        std::cout << " ";
    for (i = 0; i < 2 * n - 1; ++i)
        std::cout << ch;
    std::cout << '\n';
}