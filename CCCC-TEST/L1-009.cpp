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
    return this->fra;
}

int main()
{
    long long i, mixn;
    calcfra now;
    dfra next;
    dfra next1[101];
    char t;
    std::cin >> i >> now.fra.mum >>  t >> now.fra.den;
    while (--i)
    {
        std::cin >> next.mum  >> t >> next.den;
        now.combine(next);
    }
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