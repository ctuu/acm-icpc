#include <iostream>
#include <string>
#include <array>
int main()
{
    bool ise;
    std::array<int, 1002> dp;
    dp.fill(1);
    std::string word;
    int length, i, j;
    getline(std::cin, word);
    length = word.size();
    for (j = 1, i = 1; i < length; ++i, ++j)
    {
        //odd or even
        if (dp[i - 1] == 1)
            if (word[i] == word[i - 1])
                ise = 1;
            else
                ise = 0;
        //dp
        if (ise == 1)
        {
            std::cout << "even" << " ";
            std::cout << i << " " << word[i] << " " << word[i - (2 * j - 1) ] << " " << j << std::endl;
            if (word[i] == word[i - (2 * j - 1)] && i - (2 * j - 1)  >= 0)
                dp[i] += dp[i - 1];
            else j = 0;
        }
        else
        {
            std::cout << "odd" << " ";
            std::cout << i << " " << word[i] << " " << word[i - 2 * j] << " " << j << std::endl;
            if (word[i] == word[i - 2 * j] && i - 2 * j >= 0)
                dp[i] += dp[i - 1];
            else j = 0;
        }
    }
    for (j = 0, i = 0; i < length; ++i)
        j = (j > dp[i]) ? j : dp[i];
    if (ise == 0)
        std::cout << 2 * j - 1;
    else
        std::cout << j;
    return 0;
}