#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int si = s.size();

    for (int i = 1; i <= si; ++i)
    {
        auto q = s.substr(i, si - i);
        auto w = s.substr(0, si - i);

        if (q == w)
        {
            string ans = s;
            for(int j = 1; j < k; ++j)
                ans += s.substr(si - i, i);
            cout << ans << endl;
            return 0;
        }
    }
    return 0;
}