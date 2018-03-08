#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <array>
#include <cstring>
#include <cstdio>
#include <vector>
#define M 5005
#define S 5005
using namespace std;
array<int, S> co;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int m;
        scanf("%d", &m);
        char s[S];
        scanf("%s", s);
        int ct = strlen(s);
        int ans = 0;
        for (int i = 0; i < ct; ++i) //center
        {
            int len = min(i, ct - 1 - i);
            //odd
            if (len < ans)
                continue;
            int ti, j;
            ti = i - len;
            j = i + len;
            co.fill(0);
            int sum = 0;
            for (int k = j; k > ti + co[j]; --k)
            {
                if (sum + abs(s[ti + co[j]] - s[k]) <= m)
                {
                    sum += abs(s[ti + co[j]] - s[k]);
                    ++co[j];
                    ans = max(ans, co[j]);
                }
                else
                {
                    sum -= abs(s[ti] - s[j]);
                    co[j - 1] = co[j] - 1;
                    --j;
                    ++ti;
                    ++k;
                }
            }
            if (i == ct - 1 - i)
                continue;
            else if (i < ct - 1 - i)
            {
                ti = i - len;
                j = i + len + 1;
            }
            else
            {
                ti = i - len - 1;
                j = i + len;
            }
            co.fill(0);
            sum = 0;
            for (int k = j; k > ti + co[j]; --k)
            {
                int te = abs(s[ti + co[j]] - s[k]);
                if (sum + te <= m)
                {
                    sum += te;
                    ++co[j];
                    ans = max(ans, co[j]);
                }
                else
                {
                    sum -= abs(s[ti] - s[j]);
                    co[j - 1] = co[j] - 1;
                    --j;
                    ++ti;
                    ++k;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}