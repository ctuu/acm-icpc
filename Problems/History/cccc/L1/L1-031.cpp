#include <iostream>
#include <iomanip>
int main()
{
    int i;
    double le, we;
    std::cin >> i;
    while (i--)
    {
        std::cin >> le  >> we;
        if ((le - 100) * 1.98 <= we)
            std::cout << "You are tai pang le!" << std::endl;
        else if ((le - 100) * 1.62 >= we)
            std::cout << "You are tai shou le!" << std::endl;
        else
            std::cout << "You are wan mei!" << std::endl;
    }
    return 0;
}