#include <iostream>  
using namespace std;  
int main()  
{  
    int N;     // 字符串长度  
    cin >> N;  
    char s[8001] = {0};  // 保证可存下结尾的'/0'  
    cin >> s;  
  
    // 判断是否可变为回文串  
    int b[26] = {0};   // 记录'a'~'z'出现的次数  
    for (int i = 0; i <N; i++)  
        b[s[i] - 'a']++;  // 相应字母出现次数加一  
    int odd = 0;    // 有多少个字母出现奇数次  
    char charodd = '\0';  // 出现奇数次的字母  
    for (int i = 0; i <26; i++)  
        if (b[i] % 2 == 1)  // b[i] 是奇数  
        {  
            odd++;  
            charodd = i + 'a'; // 记录该字母  
        }  
    if (odd> 1)// 不可变为回文串（当 odd 为 0 或 1 时，都可以）  
        cout << "Impossible" << endl;  
    else  
    {  
        int change = 0;     // 交换次数  
        for (int i = 0; i <N/2; i++) // 依次考虑中点左侧的字母  
        {  
            if (s[i] == charodd)  // 是 charodd，转而考虑右侧字母  
            {  
                int j = 0;  
                for (j = i; j <= N-i-1; j++) // 从左侧该位置开始，向右直至右侧对称位置，找相同字母  
                    if (s[j] == s[N-i-1])  // 找到  
                        break;  
                change += j - i;    // 需要 j-i 次移动可到左侧位置  
                for (int k = j; k > i; k--)  // 实现字母的移动  
                    s[k] = s[k-1];  
                s[i] = s[N-i-1];// 为了省事，并非两两互换，只是右边赋为左边的值，所以最后将 i 位赋值  
            }  
            else  // 考虑左侧字母  
            {  
                int j = 0;  
                for (j = N-i-1; j>= i; j--) // 从右侧对称位置开始，向左直至 i 位（向右是排序好了的），找相同字母  
                    if (s[j] == s[i])   // 找到  
                        break;  
                change += N-i-1 - j;   // 需要 N-i-j-j 次移动可到右侧位置  
                for (int k = j; k <N-i-1; k++) // 实现字母的移动  
                    s[k] = s[k+1];  
                s[N-i-1] = s[i];  
            }  
        }  
        cout << change << endl;     // 输出  
    }  
    return 0;  
}  