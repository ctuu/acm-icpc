#include <iostream>
#include <string>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    a += b;
    string word;
    do
    {
        word.insert(word.begin(), (char) (a % c + 48));
        a /= c;
    } while (a != 0);
    cout << word;
    return 0;
}