#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, s, d;
int e[510][510], dis[510], cost[510][510];
vector<int> pre[510];
bool vis[510];
const int inf = 999999;
vector<int> path, temp;
int mincost = inf;
void dfs(int v)
{
    temp.push_back(v);
    if(v==s)
    {
        int tcost = 0;
        for (int i = temp.size() - 1; i > 0; i--)
        {
            int id = temp[i], nextid = temp[i - 1];
            tcost += cost[id][nextid];
        }
        if(tcost<mincost)
        {
            mincost = tcost;
            path = temp;
        }
        temp.pop_back();
        return;
    }
    for (int i = 0; i < pre[v].size();i++)
        dfs(pre[v][i]);
    temp.pop_back();
}
int main()
{
    fill(e[0], e[0] + 510 * 510, inf);
    fill(dis, dis + 510, inf);
    scanf("%d%d%d%d", &n, &m, &s, &d);
    for (int i = 0; i < m;i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        scanf("%d ", &e[a][b]);
        e[b][a] = e[a][b];
        scanf("%d", &cost[a][b]);
        cost[b][a] = cost[a][b];
    }
    // pre[s].push_back(s);
    dis[s] = 0;
    for (int i = 0; i < n;i++)
    {
        int u = -1, minn = inf;
        for (int j = 0; j < n;j++)
        {
            if(!vis[j]&&dis[j]<minn)
            {
                u = j;
                minn = dis[j];
            }
        }
        if(u==-1)
            break;
        vis[u] = 1;
        for (int v = 0; v < n;v++)
        {
            if(!vis[v]&&e[u][v]!=inf)
            {
                if(dis[v]>dis[u]+e[u][v])
                {
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(dis[v]==dis[u]+e[u][v])
                    pre[v].push_back(u);
            }
        }
    }
    dfs(d);
    for (int i = path.size() - 1; i >= 0; i--)
        printf("%d ", path[i]);
    printf("%d %d", dis[d],mincost);
    return 0;
}
