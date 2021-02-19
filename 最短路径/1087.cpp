#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
最短路径   dijkstra+dfs
e[u][v]表示从u到v边的权值，weight[i]表示每个点的权值，
dis[i]表示从出发点到i点的最短路径长度，num[i]表示从出发点到i点的最短路径数
w[i]表示从出发点到i点的点权值之和
dis[u]+e[u][v]<dis[v]  更新dis[v] ,num[v],w[v]
dis[u]+e[u][v]=dis[v]  更新num[v],w[v]
*/
const int inf = 1e10;
bool vis[205];
int n, k;
int e[205][205], weight[205], w[205], num[205], dis[205];
int max_happiness = -1, max_avehappiness = -1;
vector<int> pre[205], ans_path, tempath;
map<string, int> book; //每个城市编号
map<int, string> g;// 每个编号对应城市  输出答案的时候要用
string start;
void dfs(int v)
{
    tempath.push_back(v);
    if (v == 1)
    {
        int hap = 0, ave_hap = 0;
        for (int i = 0; i < tempath.size(); i++)
        {
            hap += weight[tempath[i]];
        }
        ave_hap = hap / (tempath.size()-1);
        if (hap > max_happiness)
        {
            ans_path = tempath;
            max_happiness = hap;
            max_avehappiness = ave_hap;
        }
        else if (hap == max_happiness && ave_hap > max_avehappiness)
        {
            ans_path = tempath;
            max_avehappiness = ave_hap;
        }
        tempath.pop_back();
        return;
    }
    for (int i = 0; i < pre[v].size(); i++)
    {
        dfs(pre[v][i]);
    }
    tempath.pop_back();
}
int main()
{
    int cnt = 0, c;
    string temp, a, b;
    fill(e[0], e[0] + 205 * 205, inf);
    fill(dis, dis + 205, inf);
    cin >> n >> k >> start;
    book[start] = ++cnt;
    for (int i = 0; i < n - 1; i++) //给每个点编号,输入点权
    {
        cin >> temp >> c;
        book[temp] = ++cnt;
        g[cnt] = temp;
        weight[book[temp]] = c;
    }
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b;
        scanf("%d", &e[book[a]][book[b]]);
        e[book[b]][book[a]] = e[book[a]][book[b]];
    }
    dis[book[start]] = 0;
    num[book[start]] = 1;
    for (int i = 1; i <= n; i++)
    {
        int u = -1, minn = inf;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && dis[j] < minn)
            {
                u = j;
                minn = dis[j];
            }
        }
        if (u == -1)
        {
            break;
        }
        vis[u] = 1;
        for (int v = 1; v <= n; v++)
        {
            if (!vis[v] && e[u][v] != inf)
            {
                if (dis[v] > dis[u] + e[u][v]) //最短路径优先
                {
                    dis[v] = dis[u] + e[u][v];
                    num[v] = num[u];
                    w[v] = w[u] + weight[v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if (dis[v] == dis[u] + e[u][v])
                {
                    num[v] = num[v] + num[u];
                    pre[v].push_back(u);
                    if (w[u] + weight[v] > w[v])
                    {
                        w[v] = weight[v] + w[u];
                    }
                }
            }
        }
    }
    dfs(book["ROM"]);
    cout << num[book["ROM"]] << " " << dis[book["ROM"]] << " " << max_happiness << " " << max_avehappiness << endl;
    cout << start;
    for (int i = ans_path.size() - 2; i >= 0; i--)
        cout << "->" << g[ans_path[i]];
    return 0;
}