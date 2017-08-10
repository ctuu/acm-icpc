#include <iostream>
#include <iomanip>
void swapnum(double &a, double &b);
int main()
{
    double x1, x2, y1, y2;
    double x3, x4, y3, y4;
    double mx, lx, my, ly;
    double tx, ty;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    swapnum(x1, x2);
    swapnum(y1, y2);
    swapnum(x3, x4);
    swapnum(y3, y4);
    mx = (x2 > x4) ? x2 : x4;
    lx = (x1 < x3) ? x1 : x3;
    my = (y2 > y4) ? y2 : y4;
    ly = (y1 < y3) ? y1 : y3;
    tx = (x2 - x1) + (x4 - x3) - mx + lx;
    ty = (y2 - y1) + (y4 - y3) - my + ly;
    if (tx <= 0 || ty <= 0)
        std::cout << "0.00" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(2) << tx *ty << std::endl;
    return 0;
}

void swapnum(double &a, double &b)
{
    double temp;
    if (a > b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    return;
}