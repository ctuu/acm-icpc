#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
using A = array<int, 9>;
int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int cantor(A ar)
{
    int sum = 0;
    for (int i = 0; i < 9; ++i)
    {
        int rnk = 0;
        for (int j = i + 1; j < 9; ++j)
            if (ar[i] > ar[j])
                rnk++;
        sum += rnk * fact[8 - i];
    }
    return sum+1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    A oar;
    string len = "12345X678";
    for (int i = 0; i < 9; ++i)
        oar[i] = len[i] - '0';
    cout << cantor(oar)<<endl;
    return 0;
}