#include <iostream>
#define MAXCH 8001
void swap(char *a, char *b);
int tot;
int main()
{
    int n, i, isodd = 0, temp;
    char *be, *end;
    char oddch = ' ';
    char tch;
    int cha[26] = {0};
    char ch[MAXCH];

    std::cin >> n;
    for (i = 0; i < n; ++i)
    {
        std::cin >> ch[i];
        ++cha[ch[i] - 97];
    }
    for (i = 0; i < 26; ++i)
        if (cha[i] & 01)
        {
            ++isodd;
            oddch = i + 97;
        }
    if (isodd > 1)
        std::cout << "Impossible";
    else
    {
        be = ch;
        end = ch + n - 1;
        for (i = 0; i < n / 2; ++i, ++be)
        {
            if (*be == oddch)
                for (temp = i; temp < n / 2; ++temp)
                    swap(&ch[temp], &ch[temp + 1]);
            else
            {
                for (temp = 0; *be != *end; ++temp)
                    --end;
                tch = *end;
                std::cout << tch << std::endl;
                for (; temp > 0; --temp, ++end)
                    swap(end, end + 1);
            }
        }
    }
    for (i = 0; i < n; ++i)
        std::cout << ch[i];
    std::cout << tot;
    return 0;
}

void swap(char *a, char *b)
{
    char c = *a;
    *a = *b;
    *b = c;
    ++tot;
}