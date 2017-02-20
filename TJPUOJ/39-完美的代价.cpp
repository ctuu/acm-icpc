#include <iostream>
int main()
{
    bool ist = 0;
    int n, i, te;
    int cha[26] = {0};
    char ch[8001];
    std::cin >> n;
    for (i = 0; i < n; ++i)
    {
        std::cin >> ch[i];
        te = ch[i] - 97;
        ++cha[te];
    }

    for (i = 0; i < 26; ++i)
    {
        std::cout << i << " " << cha[i] << std::endl;
        if (!ist && cha[i] > 0)
        {
            if (n & 01 && cha[i] & 01)
            {
                ist = 1;
                te = i;
            }
            else if (!(n & 01) && cha[i] & 01)
            {
                std::cout << "Impossible";
                return 0;
            }
        }
        else if (cha[i] && cha[i] & 1)
        {
            std::cout << "Impossible";
            return 0;
        }
    }
    return 0;
}