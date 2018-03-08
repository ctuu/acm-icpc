#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string cur;
        cin >> cur;
        bool jud = 0;
        int jp, ja, jt;
        jp = ja = jt = -1;
        for ( int i = 0; i < cur.size(); ++i)
        {
            if (cur[i] != 'P' && cur[i] != 'A' && cur[i] != 'T')
            {
                jud = 1;
                break;
            }
            if (cur[i] == 'P')
            {
                if (jp == -1)
                    jp = i;
                else
                {
                    jud = 1;
                    break;
                }
            }
            else if (cur[i] == 'A')
            {
                if (jp != -1 && jt == -1)
                {
                    ja = i;
                }
            }
            else if (cur[i] == 'T')
             {
                 if (ja != -1 && jt == -1)
                     jt = i;
                else
                {
                    jud = 1;
                    break;
                }
             }
        }
        if (cur.size() - 1 - jt != (ja - jp) * jp)
            jud = 1;
        if (jud)
            cout << "NO";
        else
            cout << "YES";
        cout << endl;
    }
    return 0;
}
