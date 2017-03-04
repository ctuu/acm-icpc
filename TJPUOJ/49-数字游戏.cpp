#include <iostream>
int main()
{
    long long n, k, T, i, sum, num;
    std::cin >> n >> k >> T;
    sum = i = num = 1;
    while (--T)
    {
        num += n*i+ (n-1)*n/2;
        num %= k;
        sum += num;
        i+=n;
    }
    std::cout << sum;
    return 0;
}