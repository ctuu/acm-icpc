#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int row, col;
    string word;
    cin >> row;
    while (cin.get()!= '\n');
    getline(cin,word);
    col = word.size() / row + ((word.size()%row==0)?0:1);
    for (int i = row-1;i > -1; --i)
    {
        for (int j = col; j > 0; --j)
        {
            int num = row * j - 1 - i;
            if (word.size() <= num)
                cout << " ";
            else cout << word[num];
        }
        if (i > 0) cout << endl;
    }
    return 0;
}
