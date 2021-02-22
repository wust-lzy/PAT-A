#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
坑点是one-way状态量表示 单向路或者双向路
最短路径   2个dijkstra+2个dfs    
e[u][v]表示从u到v边的权值
dis[i]表示从出发点到i点的最短路径长度，times[i]表示从出发点到i点的最短时间
2个dfs的作用分别是 在最短路径中找出最快路径
在最快路径中找到站点最少的路径
*/
const int inf = 1e10;
int n, m;
int start, END, mintime = inf, minintersections = inf;
bool vis[510];
int e[510][510], t[510][510], dis[510], times[510];
vector<int> pre1[510], pre2[510], ans1path, ans2path, tempath1, tempath2;
void dfs1(int v)
{
    tempath1.push_back(v);
    if (v == start)
    {
        int cost = 0;
        for (int i = tempath1.size() - 1; i > 0; i--)
        {
            int id = tempath1[i], next = tempath1[i - 1];
            cost += t[id][next];
        }
        if (cost < mintime)
        {
            mintime = cost;
            ans1path = tempath1;
        }
        tempath1.pop_back();
        return;
    }
    for (int i = 0; i < pre1[v].size(); i++)
    {
        dfs1(pre1[v][i]);
    }
    tempath1.pop_back();
}
void dfs2(int v)
{
    tempath2.push_back(v);
    if (v == start)
    {
        if (minintersections > tempath2.size())
        {
            minintersections = tempath2.size();
            ans2path = tempath2;
        }
        tempath2.pop_back();
        return;
    }
    for (int i = 0; i < pre2[v].size(); i++)
    {
        dfs2(pre2[v][i]);
    }
    tempath2.pop_back();
}
int main()
{
    int n, m;
    fill(e[0], e[0] + 510 * 510, inf);
    fill(dis, dis + 510, inf);
    fill(t[0], t[0] + 510 * 510, inf);
    fill(times, times + 510, inf);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c, d, ee;
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &ee);
        e[a][b] = d;
        t[a][b] = ee;
        if (c == 0)
        {
            e[b][a] = d;
            t[b][a] = ee;
        }
    }
    scanf("%d %d", &start, &END);
    dis[start] = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1, minn = inf;
        for (int j = 0; j < n; j++)
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
        for (int v = 0; v < n; v++)
        {
            if (!vis[v] && e[u][v] != inf)
            {
                if (e[u][v] + dis[u] < dis[v])
                {
                    dis[v] = e[u][v] + dis[u];
                    pre1[v].clear();
                    pre1[v].push_back(u);
                }
                else if (e[u][v] + dis[u] == dis[v])
                {
                    pre1[v].push_back(u);
                }
            }
        }
    }
    dfs1(END);
    fill(vis, vis + 510, false);
    times[start] = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1, minn = inf;
        for (int j = 0; j < n; j++) //找到起点
        {
            if (!vis[j] && times[j] < minn)
            {
                u = j;
                minn = times[j];
            }
        }
        if (u == -1)
            break;
        vis[u] = 1;
        for (int v = 0; v < n; v++)
        {
            if (!vis[v] && t[u][v] != inf)
            {
                if (t[u][v] + times[u] < times[v])
                {
                    times[v] = t[u][v] + times[u];
                    pre2[v].clear();
                    pre2[v].push_back(u); //记录路径
                }
                else if (t[u][v] + times[u] == times[v])
                {
                    pre2[v].push_back(u);
                }
            }
        }
    }
    dfs2(END);
    //Distance = 3; Time = 4: 3 -> 2 -> 5
    if (ans1path == ans2path)
    {
        printf("Distance = %d; Time = %d: ", dis[END], times[END]);
        for (int i = ans1path.size() - 1; i >= 0; i--)
        {
            printf("%d", ans1path[i]);
            if (i != 0)
            {
                printf(" -> ");
            }
        }
        return 0;
    }

    //Distance = 6: 3 -> 4 -> 8 -> 5
    printf("Distance = %d: ", dis[END]);
    for (int i = ans1path.size() - 1; i >= 0; i--)
    {
        printf("%d", ans1path[i]);
        if (i != 0)
        {
            printf(" -> ");
        }
    }
    cout << endl;
    //Time = 3: 3 -> 1 -> 5
    printf("Time = %d: ", times[END]);
    for (int i = ans2path.size() - 1; i >= 0; i--)
    {
        printf("%d", ans2path[i]);
        if (i != 0)
        {
            printf(" -> ");
        }
    }
    return 0;
}
/*
Distance = 6: 3 -> 4 -> 8 -> 5
Time = 3: 3 -> 1 -> 5
Distance = 6: 3 -> 4 -> 8 -> 5
Time = 3: 3 -> 1 -> 5
*/