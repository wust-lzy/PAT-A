#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
dijkstra算法
e[u][v]表示从u到v边的权值，weight[i]表示每个点的权值，
dis[i]表示从出发点到i点的最短路径长度，num[i]表示从出发点到i点的最短路径数
w[i]表示从出发点到i点的点权值之和
dis[u]+e[u][v]<dis[v]  更新dis[v] ,num[v],w[v]
dis[u]+e[u][v]=dis[v]  更新num[v],w[v]
...
*/
int n, m, c1, c2;//点数，边数，起点，终点
bool vis[505];
const int inf = 999999;
int e[505][505], weight[510], dis[510], num[505], w[510];
int main()
{
    cin >> n >> m >> c1 >> c2;
    for (int i = 0; i < n;i++)
        cin >> weight[i];
    fill(e[0], e[0] + 505 * 505, inf);
    fill(dis, dis + 510, inf);
    int a, b, c;
    for (int i = 0; i < m;i++)
    {
        cin >> a >> b >> c;
        e[a][b] = c;
        e[b][a] = c;
    }
    dis[c1] = 0;
    w[c1] = weight[c1];
    num[c1] = 1;
    for (int i = 0; i < n;i++)
    {
        int u = -1, minn = inf;//找到起点u
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
                if(dis[u]+e[u][v]<dis[v])
                {
                    dis[v] = dis[u] + e[u][v];
                    num[v] = num[u];
                    w[v] = w[u] + weight[v];
                }
                else if(dis[u]+e[u][v]==dis[v])
                {
                    num[v] = num[v] + num[u];
                    if(w[u]+weight[v]>w[v])
                        w[v] = w[u] + weight[v];
                }
            }
        }
    }
    cout << num[c2] << " " << w[c2] << endl;
    return 0;
}