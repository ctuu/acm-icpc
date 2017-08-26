#include <iostream>
#include <regex>
#include <string>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s1, s2, s3 = "(.)(\\1)*";
        cin >> s1 >> s2;
        for (auto i = s2.begin(); i < s2.end() - 1; ++i)
        {
            if (*i == '.' && *(i + 1) == '*')
            s2.replace(i, i + 2, s3);
        }
        // cout << s2 << endl;
        regex reg1(s2);
        bool ans = regex_match(s1, reg1);
        if (ans)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}