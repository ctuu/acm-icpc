#include <iostream>
#include <string>
char M[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
int Q[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
int main()
{
    std::string id;
    int i, te, ect = 0, j;
    std::cin >> i;
    while (i--)
    {
        bool er = 0;
        std::cin >> id;
        for (te = 0; te < 17; ++te)
            if (id[te] == 'X')
                er = 1;
        for (te = 0, j = 0; j < 17; ++j)
            te += (id[j] - '0') * Q[j];
        te %= 11;
        if (M[te] != id[17])
            er = 1;
        if (er)
        {
            std::cout << id << std::endl;
            ++ect;
        }
    }
    if (!ect)
        std::cout << "All passed";
    return 0;
}