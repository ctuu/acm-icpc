#include <algorithm>
#include <ctime>
#include <iostream>
using namespace std;
const int N = 500000;
const int LE = 1000000;
int a[LE + 7], b[LE + 7], c[LE + 7];
int rad(int x)
{
    return rand() % x;
}

void q_swap(int *l, int *r)
{
    int tmp = *l;
    *l = *r;
    *r = tmp;
}

void q_sort(int *l, int *r)
{
    int *s = l, *m = --r;
    r--;
    if (l > r)
        return;
    while (l < r)
    {
        while (*l < *m && l < r)
            ++l;
        while (*r >= *m && l < r)
            --r;
        q_swap(l, r);
    }
    if (*l > *m)
        q_swap(l, m);
    q_sort(s, l + 1);
    q_sort(r + 1, m + 1);
}

int main()
{
    srand(time(NULL));
    int ct = 0;
    int t = rad(1000);
    cout << t << endl;
    while (t--)
    {
        int n = rad(LE);
        for (int i = 0; i < n; ++i)
        {
            a[i] = rad(2 * N) - N;
            b[i] = c[i] = a[i];
        }
        sort(b, b + n);
        q_sort(c, c + n);
        bool fl = 1;
        for (int i = 0; i < n && fl; ++i)
            if (b[i] != c[i])
                fl = 0;

        if (fl)
            ;
        //     cout << "Successful." << endl;
        else
        {
            cout << "Failed." << endl;
            cout << "#define N " << n << endl;
            cout << "int a[N] = {";
            for (int i = 0; i < n; ++i)
            {
                if (i)
                    cout << ", ";
                cout << a[i];
            }
            cout << "};" << endl;
            for (int i = 0; i < n; ++i)
            {
                if (i)
                    cout << ", ";
                cout << c[i];
            }
            cout << endl;
            ++ct;
        }
    }
    cout << "TSF: " << ct << endl;
    return 0;
}