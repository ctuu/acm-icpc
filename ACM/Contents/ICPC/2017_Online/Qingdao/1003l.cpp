#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010;

struct Trie
{
    int next[maxn][26], fail[maxn], end[maxn]; // 字母的字典序编号 失败指针 以此结点为末尾的单词个数
    int root, L;                               // 根结点 总的结点数

    int newnode()
    {
        for (int i = 0; i < 26; i++)
            next[L][i] = -1;
        end[L++] = 0;
        return L - 1;
    }

    void init()
    {
        L = 0;
        root = newnode();
    }

    void insert(char buf[])
    { // 建立 trie 树
        int len = strlen(buf);
        int now = root;
        for (int i = 0; i < len; i++)
        {
            if (next[now][buf[i] - 'a'] == -1)
                next[now][buf[i] - 'a'] = newnode();
            now = next[now][buf[i] - 'a'];
        }
        end[now]++;
    }

    void build()
    { // 初始化 fail 指针，BFS
        queue<int> Q;
        fail[root] = root;
        for (int i = 0; i < 26; i++) // 处理初始的元素
            if (next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root; // 第一个元素 fail 必指向根
                Q.push(next[root][i]);
            }
        while (!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for (int i = 0; i < 26; i++)
                if (next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }

    int query(char buf[])
    { // 扫描文本串
        int len = strlen(buf);
        int now = root;
        int res = 0;
        for (int i = 0; i < len; i++)
        {
            if (buf[i] >= 'a' && buf[i] <= 'z')
                now = next[now][buf[i] - 'a']; // 结合具体题目修改
            else if (buf[i] >= 'A' && buf[i] <= 'Z')
                now = next[now][buf[i] - 'A'];
            else
                continue;
            int temp = now;
            while (temp != root)
            {
                res += end[temp];
                end[temp] = 0;
                temp = fail[temp];
            }
        }
        return res;
    }

    void debug()
    { // 调试
        for (int i = 0; i < L; i++)
        {
            printf("id = %3d,fail = %3d,end = %3d,chi = [", i, fail[i], end[i]);
            for (int j = 0; j < 26; j++)
                printf("%2d", next[i][j]);
            printf("]\n");
        }
    }
};
char buf[100002], tmp[100002];
int nu[100001];
Trie ac;

int main()
{
    int T;
    int n;
    scanf("%d", &T);
    while (T--)
    {
        int ma = 0;
        scanf("%d\n", &n);
        ac.init(); ////////
        gets(buf);
        for (int i = 0; i < nu[0]; ++i)
            tmp[i] = buf[i];
        int ina = 0, lea = nu[0];
        for (int i = 1; i < n; i++)
        {
            gets(buf);
            nu[i] = strlen(buf) + nu[i - 1];
            for (int j = nu[i - 1]; j < nu[i]; ++j)
                tmp[j] = buf[j - nu[i - 1]];
            if (nu[i] - nu[i - 1] > lea)
            {
                ina = nu[i - 1];
                lea = nu[i] - nu[i - 1];
            }
            tmp[nu[i]] = '\0';
        }
        for (int i = 0; i < n; i++)
        {
            if (nu[i] != ina)
            {
                for (int j = nu[i - 1]; j < nu[i]; ++j)
                    buf[j - nu[i - 1]] = tmp[j];
                buf[nu[i] - nu[i - 1]] = '\0';
                ac.insert(buf);
            }
        }
        ac.build();
        for (int i = ina; i < ina + lea; ++i)
            buf[i - ina] = tmp[i];
        buf[lea] = '\0';
        ma = ac.query(buf);
        if (n - 1 == ma)
            puts(buf);
        else
            puts("NO");
    }
    return 0;
}