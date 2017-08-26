#include <iostream>
#include <algorithm>
#include <array>
#include <string>
#include <vector>
using namespace std;
const int N = 1000007;

string T, P;
int pi[N];

void COMPUTER_PREFIX_FUNCTION(string P)
{
    int m = P.length(), i, k;
    for (k = pi[0] = -1, i = 1; i < m; i++)
    {
        while (k > -1 && P[k + 1] != P[i])
            k = pi[k];
        if (P[k + 1] == P[i])
            k++;
        pi[i] = k;
    }
    cout << "COMPUTER-PREFIX-FUNCTION" << endl;
    for (i = 0; i < m; i++)
    {
        cout << pi[i] << " ";
    }
    cout << endl
         << endl;
}

void KMP_MATCHER(string T, string P)
{
    int i, n, m, k;
    n = T.length();
    m = P.length();
    for (k = -1, i = 0; i < n; i++)
    {
        while (k > -1 && P[k + 1] != T[i])
            k = pi[k];
        if (P[k + 1] == T[i])
            k++;
        if (k == m - 1)
        {
            cout << "Pattern occurs with shift " << i - m + 2 << endl;
            k = pi[k];
        }
    }
}

int a[2][1000003];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        COMPUTER_PREFIX_FUNCTION(s2);
        KMP_MATCHER(s1, s2);
    }
    return 0;
}