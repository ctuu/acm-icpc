#include <iostream>
#include <iomanip>
int main()
{
    int a, b, i, sum = 0, temp;
    std::cin >> a >> b;
    for (i = a,temp = 1; i <=b; ++i,++temp)
    {   std::cout << std::setw(5) << i;
        sum += i;
        if(temp % 5 == 0)
            std::cout <<'\n';
    }
    if (--temp % 5 != 0)
        std::cout << '\n';
    std::cout  << "Sum = " <<  sum;
    return 0;
}