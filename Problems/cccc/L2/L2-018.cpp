#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
#define MP(a, b) make_pair(a, b)
const int N = 100000;
using PID = pair<int, double>;
using AD = array<double, N>;
AD aA, bB, cC;

void input(AD &iA, int &mi)
{
    int n, e;
    double c;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> e >> c;
        iA[e] = c;
        mi = max(mi, e);
    }
}

int cls0(int be, AD &iA)
{
    int cnt = 0;
    for (int i = be; i > -1; --i)
        if (!fabs(iA[i]) < 1e-8)
            fabs(iA[i]) < 0.05 ? iA[i] = 0.0 : cnt++;
    return cnt;
}

void output(int cnt, int be, AD &iA)
{
    if (cnt == 0)
    {
        cout << "0 0 0.0" << endl;
        return;
    }
    cout << cnt;
    for (int i = be; i > -1; --i)
        if (!fabs(iA[i]) < 1e-8)
            cout << fixed << setprecision(1) << " " << i << " " << iA[i];
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int ma = 0, mb = 0;
    aA.fill(0);
    bB.fill(0);
    input(aA, ma);
    input(bB, mb);
    for (int i = ma; i >= mb; --i)
    {
        cC[i - mb] = aA[i] / bB[mb];
        for (int j = mb; j > -1; --j)
            aA[i + j - mb] -= bB[j] * cC[i - mb];
    }
    int ctc = cls0(ma - mb, cC);
    int cta = cls0(mb, aA);
    // cout << ctc << " " << cta << endl;
    output(ctc, ma - mb, cC);
    output(cta, mb - 1, aA);
    return 0;
}