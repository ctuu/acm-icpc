#include <iostream>
#include <string>
#include <vector>
int main()
{
    std::vector<std::string> no(1001);
    std::string temch;
    int i, n, temp;
    int test[1001] = {0};
    std::cin >> n;
    while (n--)
    {
        std::cin >> temch >> temp;
        std::cin >> i;
        test[temp] = i;
        no[i] = temch;
    }
    std::cin >> n;
    while (n--)
    {
        std::cin >> i;
        std::cout << no[test[i]] << " " << test[i] << std::endl;
    }
    return 0;
}