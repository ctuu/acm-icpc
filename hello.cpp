#include <iostream>
int main()
{
    int x1 = 3;
    int x2 = 5;
    x1 ^= x2;
    x2 ^= x1;
    x1 ^= x2;
    std::cout<< "Hello World." << x1 << x2 << std::endl;
    return 0;
}