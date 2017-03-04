#include <iostream>
void ssin(int i);
int main()
{
    int n, te, tr;
    std::cin >> n;
    for (te = n; te > 1; --te)
        std::cout << "(";
    for (te = n, tr = 1; te > 1 && tr < n; --te, ++tr)
    {
        ssin(tr);
        std::cout << "+" << te << ")";
    }
    ssin(tr);
    std::cout << "+1";
    return 0;
}

void ssin(int i)
{
    int te = 1;
    for (; te < i; ++te)
    {
        std::cout << "sin(" << te;
        if (te & 1)
            std::cout << "-";
        else
            std::cout << "+";
    }
    std::cout << "sin(" << te;
    for (te = i; te > 0; --te)
        std::cout << ")";
    return;
}