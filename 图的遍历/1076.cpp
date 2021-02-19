#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
bfs遍历图
*/
const int maxn = 1010;
struct node
{
    int id, layer;
    node(int a, int b) : id(a), layer(b) {}
    node(){}
};
vector<node> adj[maxn]; //邻接表
bool vis[maxn] = {false};
int bfs(int s, int l) //start 为起点 l为层数上限
{
    int num = 0; //转发数
    queue<node> q;
    node start = node(s, 0);
    q.push(start);
    vis[start.id] = 1;
    while (!q.empty())
    {
        node temp = q.front();
        q.pop();
        int u = temp.id;
        for (int i = 0; i < adj[u].size(); i++)
        {
            node next = adj[u][i];
            next.layer = temp.layer + 1;
            if (!vis[next.id] && next.layer <= l)
            {
                q.push(next);
                vis[next.id] = 1;
                num++;
            }
        }
    }
    return num;
}
int main()
{
    node user;
    int n, l, numfollow, idfollow;
    scanf("%d%d", &n, &l);
    for (int i = 1; i <=n; i++)
    {
        user.id = i;
        scanf("%d", &numfollow);
        for (int j = 0; j<numfollow; j++)
        {
            scanf("%d", &idfollow);
            adj[idfollow].push_back(user);
        }
    }
    int query, s;
    scanf("%d", &query);
    for (int i = 0; i < query; i++)
    {
        memset(vis, false, sizeof(vis));
        scanf("%d", &s);
        int ans = bfs(s, l);
        printf("%d\n", ans);
    }
    return 0;
}
/*
7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6
*/