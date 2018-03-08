#include <iostream>
int setn(int n, int ma);
void show(int n, int ma);
int main()
{
    int tonum[1048576] = {0};
    int n, ln, ma = 1;
    int temp;
    int nums[20] = {0};
    std::cin >> n;
    for (ln = n; ln > 1; ln--)
        ma *= 2;
    for (ln = 0; ln < n; ++ln)
    {
        nums[ln] = setn(n, ma);
        tonum[nums[ln]]++;
    }
    for (ma = 0, ln = 0; ln < n; ++ln)
        ma = (tonum[ma] > tonum[nums[ln]]) ? ma : nums[ln];
    show(n, ma);
    return 0;
}

int setn(int n, int ma)
{
    int i = n, num;
    int ct = 0;
    while (i--)
    {
        std::cin >> num;
        ct += num * ma;
        ma /= 2;
    }
    return ct;
}

void show(int n, int ma)
{
    int i;
    char ps[20];
    const static int size = n;
    for (i = size - 1; i >= 0; i--, ma >>= 1)
        ps[i] = (01 & ma) + '0';
    ps[size] = '\0';
    for (i = 0; i < n; ++i)
        if (ps[i] == '1')
            std::cout << i + 1 << " ";
}