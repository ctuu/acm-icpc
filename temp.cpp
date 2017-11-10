void dfs(int u)
{
    //记录dfs遍历次序
    static int counter = 0;

    //记录节点u的子树数
    int children = 0;

    ArcNode *p = graph[u].firstArc;
    visit[u] = 1;

    //初始化dfn与low
    dfn[u] = low[u] = ++counter;

    for (; p != NULL; p = p->next)
    {
        int v = p->adjvex;
        if (edge(u, v) 已经被标记)
            continue;

        //节点v未被访问，则(u,v)为树边
        if (!visit[v])
        {
            children++;
            parent[v] = u;
            edgeStack[top++] = edge(u, v); // 将边入栈
            dfs(v);

            low[u] = min(low[u], low[v]);

            //case (1)
            if (parent[u] == NIL && children > 1)
            {
                printf("articulation point: %d\n", u);
                // mark edge
                // 将边出栈，直到当前边出栈为止，这些边标记为同一个组
                do
                {
                    nowEdge = edgeStack[top];
                    top--;
                    // 标记nowEdge
                } while (nowEdge != edge(u, v))
            }

            //case (2)
            if (parent[u] != NIL && low[v] >= dfn[u])
            {
                printf("articulation point: %d\n", u);
                // mark edge
                // 将边出栈，直到当前边出栈为止，这些边标记为同一个组
                do
                {
                    nowEdge = edgeStack[top];
                    top--;
                    // 标记nowEdge
                } while (nowEdge != edge(u, v))
            }
        }

        //节点v已访问，则(u,v)为回边
        else if (v != parent[u])
        {
            edgeStack[top++] = edge(u, v);
            low[u] = min(low[u], dfn[v]);
        }
    }
}