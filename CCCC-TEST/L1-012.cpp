#include <iostream>
int main()
{
    int i;
    int num[10] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
    std::cin >> i;
    std::cout << "2^" << i << " = " << num[i - 1];
    return 0;
}