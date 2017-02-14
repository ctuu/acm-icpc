//1230002,123000
/*
20 0000 0000
[shi]-yi-[qian bai shi]-wan-[qian ban shi]-()
*/
#include <iostream>
#include <vector>
#include <string>
bool isl = false;
int speak(int a, int b);
int main()
{
    long long num, temp;
    int on, tw, th, ct;
    on = tw = th = -1;
    std::cin >> num;
    for (ct = 1, temp = num; temp > 1; ++ct)
        temp /= 10;
    th = num;
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
    if (speak(-2, on) == 0)
        std::cout << "yi ";
    if (speak(on, tw) == 0)
        std::cout << "wan ";
    speak(tw, th);
    return 0;
}

int speak(int a, int b)
{
    int c = b;
    int d = c;
    std::vector<std::string> v1{"yi ", "er ", "san ", "si ", "wu ", "liu ", "qi ", "ba ", "jiu "};
    if (b <= 0)
        return -1;

    if (c >= 1000)
    {
        if (a > -1 || c > 2000)
            std::cout << v1[c / 1000 - 1];
        c -= b / 1000 * 1000;
        d = c;
        std::cout << "qian ";
        isl = false;
    }
    else if (a >= 0)
        isl = true;

    if (c >= 100)
    {
        if (isl)
        {
            std::cout << "ling ";
            isl = false;
        }
        if (a > -1 || c > 200)
            std::cout << v1[c / 100 - 1];
        c -= d / 100 * 100;
        d = c;
        std::cout << "bai ";
        isl = false;
    }
    else if (a >= 0)
        isl = true;

    if (c >= 10)
    {
        if (isl)
        {
            std::cout << "ling ";
            isl = false;
        }
        if (a > -1 || c > 20)
            std::cout << v1[c / 10 - 1];
        c -= d / 10 * 10;
        d = c;
        std::cout << "shi ";
        isl = false;
    }
    else if (a >= 0)
        isl = true;

    if (c > 0)
    {
        if (isl)
        {
            std::cout << "ling ";
            isl = false;
        }

        std::cout << v1[c - 1];
    }
    return 0;
}