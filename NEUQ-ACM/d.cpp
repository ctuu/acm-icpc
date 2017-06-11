/*
example;
 /\
/__\

   /\  1,4
  /__\
 /\  /\ 3, 2 // 3, 6
/__\/__\

       /\     1, 8
      /__\
     /\  /\
    /__\/__\
   /\      /\  5,4 //  5, 12
  /__\    /__\
 /\  /\  /\  /\
/__\/__\/__\/__\

               /\  1,16
              /__\
             /\  /\
            /__\/__\
           /\      /\  5, 12 // 5, 20
          /__\    /__\
         /\  /\  /\  /\
        /__\/__\/__\/__\
       /\              /\  9, 8//  9,24
      /__\            /__\
     /\  /\          /\  /\
    /__\/__\        /__\/__\
   /\      /\      /\      /\
  /__\    /__\    /__\    /__\
 /\  /\  /\  /\  /\  /\  /\  /\
/__\/__\/__\/__\/__\/__\/__\/__\
*/

#include <iostream>
#include <string>
#include <array>
#include <cmath>
using namespace std;
void draw(int x, int y, int level);
array<array<string, 5000>, 5000> xrbs;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (auto &i: xrbs)
        i.fill(" ");
    draw(1, pow(2, n), n);
    for (int i = 1; i <= pow(2, n); ++i)
    {
        int j;
        for (j = 1; j <= pow(2, n + 1); ++j)
            cout << xrbs[i][j];
        //cout << << i << ' ' << j;
        cout << endl;
    }
    return 0;
}

void draw(int x, int y, int level)
{
    if (level > 1)
    {
        draw(x, y, level - 1);
        draw(x + pow(2, level - 1), y - pow(2, level - 2) - (pow(2, level - 1)/2), level - 1);
        draw(x + pow(2, level - 1), y + pow(2, level - 2) + (pow(2, level - 1)/2), level - 1);
    }
    xrbs[x][y] = xrbs[x + 1][y - 1] = "/";
    xrbs[x][y + 1] = xrbs[x + 1][y + 2] = "\\";
    xrbs[x + 1][y]= "_";
    xrbs[x + 1][y + 1] = "_";
    //cout << x << ' ' << y << ' ' << level << endl;
    return;
}