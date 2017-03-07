#include <iostream>
struct drink
{
    int dod;
    int shout;
    int ges;
};
int main()
{
    int i, ad, bd;
    drink a, b;
    std::cin >> a.dod >> b.dod >> i;
    ad = a.dod;
    bd = b.dod;
    while (i--)
    {
        bool isa = 0, isb = 0;
        std::cin >> a.shout >> a.ges >> b.shout >> b.ges;
        if (a.ges == a.shout + b.shout)
            isa = 1;
        if (b.ges == a.shout + b.shout)
            isb = 1;
        if (isa && isb)
            continue;
        else if (isa)
            --a.dod;
        else if (isb)
            --b.dod;
        if (a.dod == -1)
        {
            std::cout << "A" << std::endl << bd - b.dod;
            return 0;
        }
        else if (b.dod == -1)
        {
            std::cout << "B" << std::endl << ad - a.dod;
            return 0;
        }
    }
    return 0;
}