#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

struct node
{
    node *next[26], *fail;
    int count;
    node()
    {
        fail = NULL;
        count = 0;
        memset(next, 0, sizeof(next));
    }
};
queue<node *> q;
char word[100002], str[100002], tmp[100002];
int nu[100001];

int ins(char *str, node *root)
{
    node *p = root;
    int i = 0, index;
    while (str[i])
    {
        index = str[i] - 'a';
        if (!p->next[index])
            p->next[index] = new node();
        p = p->next[index];
        i++;
    }
    p->count++;
    return 0;
}

int build(node *root)
{
    root->fail = NULL;
    q.push(root);
    while (!q.empty())
    {
        node *p = NULL;
        node *temp = q.front();
        q.pop();
        for (int i = 0; i < 26; i++)
            if (temp->next[i])
            {
                if (temp == root)
                    temp->next[i]->fail = root;
                else
                {
                    p = temp->fail;
                    while (p)
                    {
                        if (p->next[i])
                        {
                            temp->next[i]->fail = p->next[i];
                            break;
                        }
                        p = p->fail;
                    }
                    if (!p)
                        temp->next[i]->fail = root;
                }
                q.push(temp->next[i]);
            }
    }
    return 0;
}

int solve(node *root)
{
    int i = 0, cut = 0, index, len = strlen(str);
    node *p = root;
    while (str[i])
    {
        index = str[i] - 'a';
        while (!p->next[index] && p != root)
            p = p->fail;
        p = p->next[index];
        p = (p == NULL) ? root : p;
        node *temp = p;
        while (temp != root && temp->count != -1)
        {
            cut += temp->count;
            temp->count = -1;
            temp = temp->fail;
        }
        i++;
    }
    return cut;
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        node *root = new node();
        int n, ma = 0;
        scanf("%d\n", &n);
        gets(word);
        nu[0] = strlen(word);
        for (int i = 0; i < nu[0]; ++i)
            tmp[i] = word[i];
        int ina = 0, lea = nu[0];
        for (int i = 1; i < n; i++)
        {
            gets(word);
            // printf("ow %s\n", word);
            nu[i] = strlen(word) + nu[i - 1];
            for (int j = nu[i - 1]; j < nu[i]; ++j)
                tmp[j] = word[j - nu[i - 1]];
            if (nu[i] - nu[i - 1] > lea)
            {
                ina = nu[i - 1];
                lea = nu[i] - nu[i - 1];
            }
            tmp[nu[i]] = '\0';
        }
        for (int i = ina; i < ina + lea; ++i)
            str[i - ina] = tmp[i];
        str[lea] = '\0';
        for (int i = 0; i < n; i++)
        {
            if (nu[i] != ina)
            {
                for (int j = nu[i - 1]; j < nu[i]; ++j)
                    word[j - nu[i - 1]] = tmp[j];
                word[nu[i] - nu[i - 1]] = '\0';
                ins(word, root);
            }
            // printf("wo = %s\n",word);
        }
        build(root);
        //   scanf("%s",str);
        // printf("str = %s\n",str);
        if (n - 1 == solve(root))
            puts(str);
        else
            puts("NO");
    }
    return 0;
}