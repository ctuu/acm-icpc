#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> nuo;
    vector<int> nue;
    int sum  = 0;
    for (int i = 0; i < n; ++i)
    {
        int te;
        cin >> te;
        if (abs(te) % 2 == 0)
        {
            if (te > 0)
                sum += te;
        }
        else
            nuo.push_back(te);
    }
    sort(nuo.begin(), nuo.end(), greater<int>());
    int i;
    sum += nuo[0];
    for (i = 1; i < nuo.size(); ++i)
    {
        if (nuo[i] < 0)
        {
            if (i % 2 != 0)
                break;
            else
                sum = max(sum - nuo[i-1], sum + nuo[i]);
        }
        else
            sum += nuo[i];
    }
    if (i > 0 && nuo[i-1] > 0 && sum % 2 == 0)
        sum -= nuo[i-1];
    cout << sum;
    return 0;
}
