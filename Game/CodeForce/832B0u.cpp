#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    array<bool, 26> gl;
    gl.fill(false);
    string sgl, s;
    cin >> sgl >> s;

    for (auto i : sgl)
        gl[i - 'a'] = true;
    int mod = 1; //a*a
    if (*s.cbegin() == '*')
        mod = 0; //*aa
    else if (*s.crbegin() == '*')
        mod = 2; //aa*
    bool np = true;
    for (auto i : s)
        if (i == '*')
            np = false;

    int n;
    cin >> n;
    while (n--)
    {
        bool ans = true;
        string le;
        cin >> le;
        if (mod == 0)
        {
            if (s.size() - 1 > le.size())
            {
                ans = false;
            }
            else
            {
                auto a = s.crbegin();
                auto b = le.crbegin();
                while (a != s.crend() && b != le.crend())
                {
                    if (*a == '?')
                    {
                        if (!gl[*b - 'a'])
                        {
                            ans = false;
                            break;
                        }
                    }
                    else if (*a == '*')
                    {
                        while (b != le.crend())
                        {
                            if (gl[*b - 'a'])
                            {
                                ans = false;
                                break;
                            }
                            b++;
                        }
                    }
                    else if (*a != *b)
                    {
                        ans = false;
                        break;
                    }
                    ++a;
                    ++b;
                    if (*a == '*' && b == le.crend())
                        break;
                }
            }
        }
        if (mod == 1)
        {
            if (np && s.size() != le.size())
                ans = false;
            else if (s.size() - 1 > le.size())
            {
                ans = false;
            }
            else
            {
                auto a = s.cbegin();
                auto b = le.cbegin();
                auto c = s.cend() - 1;
                auto d = le.cend() - 1;

                auto rs = le.cbegin();
                auto re = le.cend();
                while (a != s.cend() && b != le.cend())
                {
                    if (*a == '?')
                    {
                        if (!gl[*b - 'a'])
                        {
                            ans = false;
                            break;
                        }
                    }
                    else if (*a == '*')
                    {
                        rs = b;
                        break;
                    }
                    else if (*a != *b)
                    {
                        ans = false;
                        break;
                    }
                    ++a;
                    ++b;
                }

                while (c >= s.cbegin() && d >= le.cbegin())
                {
                    if (*c == '?')
                    {
                        if (!gl[*d - 'a'])
                        {
                            ans = false;
                            break;
                        }
                    }
                    else if (*c == '*')
                    {
                        re = d;
                        break;
                    }
                    else if (*c != *d)
                    {
                        ans = false;
                        break;
                    }
                    if (c == s.cbegin() || d == le.cbegin())
                        break;
                    --c;
                    --d;
                }
                if (*a == '*')
                {
                    while (rs <= re)
                    {
                        if (gl[*rs - 'a'])
                        {
                            ans = false;
                            break;
                        }
                        rs++;
                    }
                }
            }
        }

        if (mod == 2)
        {
            if (s.size() - 1 > le.size())
            {
                ans = false;
            }
            else
            {
                auto a = s.cbegin();
                auto b = le.cbegin();
                while (a != s.cend() && b != le.cend())
                {
                    if (*a == '?')
                    {
                        if (!gl[*b - 'a'])
                        {
                            ans = false;
                            break;
                        }
                    }
                    else if (*a == '*')
                    {
                        while (b != le.cend())
                        {
                            if (gl[*b - 'a'])
                            {
                                ans = false;
                                break;
                            }
                            b++;
                        }
                    }
                    else if (*a != *b)
                    {
                        ans = false;
                        break;
                    }
                    ++a;
                    ++b;
                    if (*a == '*' && b == le.cend())
                        break;
                }
            }
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}