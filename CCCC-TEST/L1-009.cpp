#include <iostream>

long long GCD(long long a,  long long b);
long long LCM(long long a, long long b);
struct dfra
{
    long long mum;
    long long den;
};

struct calcfra
{
    dfra fra;
    dfra& combine(dfra rhs);
};

dfra& calcfra::combine(dfra rhs)
{
    long long i = LCM(fra.den, rhs.den);
    fra.mum *= i / fra.den;
    rhs.mum *= i / rhs.den;
    fra.den = i;
    fra.mum += rhs.mum;
    i = GCD(fra.mum, fra.den);
    fra.mum /= i;
    fra.den /= i;
    if (fra.den < 0)
    {
        fra.den = -fra.den;
        fra.mum = -fra.mum;
    }
    return this->fra;
}

int main()
{
    long long i, mixn, n, j;
    calcfra now;
    dfra next[101];
    dfra temp;
    char t;
    std::cin >> n;
    for (i = 0; i < n; ++i)
        std::cin >> next[i].mum  >> t >> next[i].den;
    for (i = 0; i < n; ++i)
        for (j = 0; j < n - i - 1; ++j)
            if ((double)next[j].mum / next[j].den > (double)next[j + 1].mum / next[j + 1].den)
            {
                temp = next[j];
                next[j] = next[j + 1];
                next[j + 1] = temp;
            }
    now.fra.mum = next[0].mum;
    now.fra.den = next[0].den;
    // for (i = 0; i < n; ++i)
    //     std::cout << next[i].mum << "/" << next[i].den << std::endl;
    for (i = 1; i < n; ++i)
        now.combine(next[i]);
    i = GCD(now.fra.mum, now.fra.den);
    now.fra.mum /= i;
    now.fra.den /= i;
    mixn = now.fra.mum / now.fra.den;
    if (mixn)
        std::cout << mixn;
    now.fra.mum -= mixn * now.fra.den;
    if (now.fra.mum)
    {
        if (mixn)
            std::cout << " ";
        std::cout << now.fra.mum << "/" << now.fra.den;
    }
    else if (!mixn)
        std::cout << "0";
    return 0;
}

long long GCD(long long a,  long long b)
{
    if (b)
        while ((a %= b) && (b %= a));
    return a + b;
}
long long LCM(long long a, long long b)
{
    return a * b / GCD(a, b);
}