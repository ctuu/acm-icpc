#include <iostream>
#include <string>
#include <array>
#define sch '#'
int main()
{
    std::string word;
    std::array<int, 3002> len;
    getline(std::cin, word);
    // for (auto i = word.begin(); i <= word.end(); i += 2)
    //     word.insert(i, sch);
    int id = 0;
    int maxlen = 0;
    std::cout << word << std::endl;
    // for (int i = 1; i < word.size(); ++i)
    // {
    //     if (len[id] + id > i)
    //         len[i] = std::min(len[id * 2 - i], len[id] - (i - id));
    //     else
    //         len[i] = 1;
    //     while (word[i + len[i]] == word[i - len[i]])
    //         ++len[i];
    //     if (len[i] + i > id + len[id])
    //         id = i;
    //     if (maxlen < len[i])
    //         maxlen = len[i];
    // }
    for ( int i = 0; i < word.size(); ++i)
        std::cout << len[i] << " ";
    std::cout << std::endl << maxlen / 2 + 1;
    return 0;
}