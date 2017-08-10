#include <iostream>
#include <array>
#include <string>
using namespace std;
int main()
{
    array<int, 10> nu;
    nu.fill(0);
    string nwo;
    std::cin >> nwo;
    for (int i = 0; i < nwo.size(); ++i)
        ++nu[nwo[i] - '0'];
    for (int i = 0; i < 10; ++i)
        if (nu[i] > 0)
            cout << i << ":" << nu[i] << endl;
    return 0;
}
