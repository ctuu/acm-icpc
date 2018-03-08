#include <iostream>
#define MAX 1000000
bool dp[MAX];

int main()
{
    int a, b, i, j;
    std::cin >> a >> b;
    dp[a] = 1;
    dp[b] = 1;
    for (i = b + 1; i < MAX; ++i)
        if (dp[i - b])
            dp[i] = 1;
    for (i = a + 1; i < MAX; ++i)
        if (dp[i - a])
            dp[i] = 1;
    for (i = a * b; dp[i]; --i);
    std::cout << i;
    return 0;
}