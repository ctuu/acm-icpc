long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    a %= b;
    return gcd(b, a);
}