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
        string s1, s2, s3 = "(.)\\1*";
        cin >> s1 >> s2;
        s2 = regex_replace(s2, regex("\\.\\*"), s3);
        cout << s2 << endl;
        bool ans = regex_match(s1, regex(s2));
        if (ans)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}