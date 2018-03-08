#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> word;
    array<int, 50> tim;
    tim.fill(1);
    word.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> word[i];
        if (i)
            word[i] += word[i];
    }
    int le = word[0].size();
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j <= n + 1; ++j)
        {
            string sub = word[i].substr(j, le);
            if (sub == word[0])
            {
                tim[i] = j + 1;
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i)
        cout << tim[i] << " ";
    return 0;
}
