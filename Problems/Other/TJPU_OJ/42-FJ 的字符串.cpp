#include <iostream>
void dfs(int i);
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    dfs(n);
    return 0;
}
void dfs(int i)
{
    if (i > 0)
    {
        dfs(i - 1);
        std::cout << (char)('@' + i);
        dfs(i - 1);
    }
}
