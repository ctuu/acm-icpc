#include <iostream>
#include <string>
int main()
{
    int n, j;
    char ch;
    std::string word;
    std::cin >> n >> ch;
    getline(std::cin, word);
    getline(std::cin, word);
    j = word.size();
    if (j < n)
    {
        n -= j;
        while (n--)
            std::cout << ch;
        std::cout << word;
    }
    else
    {
        auto it = word.begin();
        for (j -= n; j > 0; --j)
            ++it;
        --it;
        while (it++ != word.end())
            std::cout << *it;
    }
    return 0;
}