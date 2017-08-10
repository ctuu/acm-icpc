#include <iostream>
#include <string>
int main()
{
    std::string ch = "I Love GPLT";
    for (auto s : ch)
    {
        std::cout << s;
        if (s != 'T')
            std::cout << std::endl;
    }
    return 0;
}