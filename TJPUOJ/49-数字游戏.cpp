#include <iostream>
int main()
{
    long long n, k, T, i, sum = 0, j = 1;
    std::cin >> n >> k >> T;
    for (i = 0; T--; i+=n)
    {
        if (i > 1)
            j += n * (i -1);
        j %= k;
        std::cout << j << " " <<  i << '\n' ;
        sum += j;
    }
    std::cout << sum;
    return 0;
}