#include <iostream>
#define DIGIT 3000
int main()
{
    int num[DIGIT] = {0};
    int add[DIGIT] = {0};
    int i, n, te, temp;
    std::cin >> n;
    num[0] = 1;
    for (i = 1; i < n; ++i)
    {
        for (te = 0; te < DIGIT; ++te)
            add[te] = num[te] * i;
        for (te = 0; te < DIGIT; ++te)
        {
            num[te + 1] += (add[te] + num[te]) / 10;
            num[te] = (add[te] + num[te]) % 10;
        }
    }
    for (i = DIGIT - 1, te = 0; i >= 0; --i)
    {
        if (te == 0 && num[i] == 0)
            continue;
        else
            te = 1;
        std::cout << num[i];
    }
    return 0;
}