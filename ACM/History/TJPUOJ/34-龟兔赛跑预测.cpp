#include <iostream>
int main()
{
    int v1, v2, t, s, l;
    int tt, tr, lt, lr, temp;
    std::cin >> v1 >> v2 >> t >> s >> l;
    temp = tr = lt = lr = tt = 0;
    while (lt < l && lr < l)
    {
        if (lr - lt >= t && temp == 0)
            temp = s;
        lt += v2;
        ++tt;
        ++tr;
        if (temp == 0)
            lr += v1;
        else
            --temp;
    }
    if (lt == lr)
    {
        std::cout << "D" << std::endl;
        std::cout << tt << std::endl;
    }
    else if (lt > lr)
    {
        std::cout << "T" << std::endl;
        std::cout << tt << std::endl;
    }
    else
    {
        std::cout << "R" << std::endl;
        std::cout << tr << std::endl;
    }
    return 0;
}