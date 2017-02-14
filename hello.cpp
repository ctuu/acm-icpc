#include <iostream>

int main()
{
    long long num, temp;
    int on, tw, th, ct;
    on = tw = th = -1;
    std::cin >> num;
    for (ct = 1, temp = num; temp > 10; ++ct)
        temp /= 10;
            th = num;
    std::cout<<ct<<std::endl;
    if (ct >= 5)
    {
        tw = num / 10000;
        th -= tw * 10000;
    }
    if (ct >= 9)
    {
        on = num / 100000000;
        tw -= on * 10000;
    }
    std::cout<<on<<std::endl;
    std::cout<<tw<<std::endl;
    std::cout<<th<<std::endl;
    return 0;
}