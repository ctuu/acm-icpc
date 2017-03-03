#include <iostream>
#include <string>
void swap(char &a,char &b);
int main()
{
    int i, sum = 0, j;
    std::string nst,nnd;
    std::cin >> nst >> nnd;
    for (i = 0; i < nst.size()-1; ++i)
    {
        if (nst[i] != nnd[i])
        {   swap(nst[i], nst[i+1]);
            ++sum;
        }
    }
    std::cout << sum;
    return 0;
}
void swap(char &a, char &b)
{
    if (a == '*')
        a = 'o';
    else if (a == 'o')
        a = '*';
    if (b == '*')
        b = 'o';
    else if (b == 'o')
        b = '*';
}