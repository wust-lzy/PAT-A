#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 9999999;
int cmax, n, sp, m;
int minneed = inf, minback = inf;
int e[510][510], dis[510], weight[510];
bool vis[510];
vector<int> pre[510], path, tempath;
void dfs(int v)
{
    tempath.push_back(v);
    if (v == 0)
    {
        int need = 0, back = 0;
        for (int i = tempath.size() - 1; i >= 0; i--)
        {
            int id = tempath[i];
            if (weight[id] > 0)
                back += weight[id];
            else
            {
                if (back > (0 - weight[id]))
                    back += weight[id];
                else
                {
                    need += ((0 - weight[id]) - back);
                    back = 0;
                }
            }
        }
        if (need < minneed)
        {
            minneed = need;
            minback = back;
            path = tempath;
        }
        else if (need == minneed && back < minback)
        {
            path = tempath;
            minback = back;
        }
        tempath.pop_back();
        return;
    }
    for (int i = 0; i < pre[v].size(); i++)
        dfs(pre[v][i]);
    tempath.pop_back();
}
int main()
{
    fill(e[0], e[0] + 510 * 510, inf);
    fill(dis, dis + 510, inf);
    scanf("%d%d%d%d", &cmax, &n, &sp, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &weight[i]);
        weight[i] -= cmax / 2;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        e[a][b] = c;
        e[b][a] = c;
    }
    dis[0] = 0;
    for (int i = 0; i <= n; i++)
    {
        int u = -1, minn = inf;
        for (int j = 0; j <= n; j++)
        {
            if (!vis[j] && dis[j] < minn)
            {
                u = j;
                minn = dis[j];
            }
        }
        if (u == -1)
            break;
        vis[u] = 1;
        for (int v = 0; v <= n; v++)
        {
            if (!vis[v] && e[u][v] != inf)
            {
                if (dis[v] > dis[u] + e[u][v])
                {
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if (dis[v] == dis[u] + e[u][v])
                {
                    pre[v].push_back(u);
                }
            }
        }
    }
    dfs(sp);
    printf("%d 0", minneed);
    for (int i = path.size() - 2; i >= 0; i--)
        printf("->%d", path[i]);
    printf(" %d", minback);
    return 0;
}