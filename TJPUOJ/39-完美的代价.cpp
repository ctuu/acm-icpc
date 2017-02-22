#include <iostream>
#define MAXCH 8001
int main()
{
    int n, i, isodd = 0;
    int alph[26] = {0};
    char ch[MAXCH], odd = '\0';
    std::cin >> n >> ch;
    for (i = 0; i < n; ++i)
        ++alph[ch[i] - 97];
    for (i = 0; i < 26; ++i)
        if (alph[i] & 01)
        {
            ++isodd;
            odd = i + 97;
        }
    if (isodd > 1)
        std::cout << "Impossible" << std::endl;
    else
    {
        int change = 0;
        for (i = 0; i < n / 2; ++i)
        {
            if (ch[i] == odd)
            {
                // fdejjellf
                int j = i;
                for (; j <= n -i - 1; ++j)
                    if (ch[j] == ch[n - 1 - i])
                        break;
                change += j - i;
                for (int k = j; k > i; --k)
                    ch[k] = ch[k - 1];
                ch[i] = ch[n - 1 - i];
            }
            else
            {
                int j = 0;
                for (j = n -i - 1; j > i; --j)
                    if (ch[j] == ch[i])
                        break;
                change += n - 1 - j - i;
                for (int k = j; k < n - 1 - i; ++k)
                    ch[k] = ch[k + 1];
                ch[n - 1 - i] = ch[i];
            }
        }
        std::cout << change;
    }
    return 0;
}