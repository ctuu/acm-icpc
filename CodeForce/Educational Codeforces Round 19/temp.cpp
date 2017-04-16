#include <iostream>
#include <iomanip>
#include <array>
using namespace std;
int main()
{
    array<array<double, 32>, 32> data;
    array<array<double, 32>, 32> moda;
    for (auto &d: data)
        d.fill(0);
    for (auto &d: moda)
        d.fill(0);
    for (int i = 1; i < 30; ++i)
        for (int j = 1; j <= i; ++j)
            cin >> data[i][j];
   for (int i = 1; i <= 30; ++i)
   {
       for (int j = 1; j <= i; ++j)
       {
           moda[i][j] = (data[i][j] + (moda[i - 1][j] + moda[i - 1][j - 1])/2); 
//           cout << moda[i][j] << " ";
       }
//       cout << endl;
   }
   double minn = 9999, maxn = 0;
   for (int i = 1; i <=30; ++i)
   {
        minn = min(minn, moda[30][i]);
        maxn = max(maxn, moda[30][i]);
   }
    cout << setw(10) << fixed << maxn * 2086458231 / minn;

   return 0;
}
