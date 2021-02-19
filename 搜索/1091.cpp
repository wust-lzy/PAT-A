#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
bfs求连通块的个数
每个连通块体积必须>=t才能算
读题很费劲
*/
int m, n, l, t;
struct node
{
    int x, y, z;
    node (int a,int b,int c):x(a),y(b),z(c){}
};
int go[6][3] = {{-1, 0, 0}, {1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
int book[65][1300][130]; //三维数组
bool vis[65][1300][130];
bool judge(int x,int y,int z)
{
    return x >= 0 && x < m && y >= 0 && y < n && z >= 0 && z < l;
}
int bfs(int x,int y,int z)
{
    vis[z][x][y] = 1;
    queue<node> q;
    q.push(node(x, y, z));
    int cnt = 0;
    while (!q.empty())
    {
        node temp = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < 6; i++)
        {
            int dx = temp.x + go[i][0];
            int dy = temp.y + go[i][1];
            int dz = temp.z + go[i][2];
            if (judge(dx,dy,dz)&&!vis[dz][dx][dy]&&book[dz][dx][dy])
            {
                vis[dz][dx][dy] = 1;
                q.push(node(dx,dy,dz));
            }
        }
    }
    if (cnt>=t)
    {
        return cnt;
    }
    else
    {
        return 0;
    }
}
int main()
{
    cin >> m >> n >> l >> t;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                scanf("%d", &book[i][j][k]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (!vis[i][j][k]&&book[i][j][k])
                {
                    ans += bfs(j,k,i);
                }
                
            }
        }
    }
    cout << ans;

    return 0;
}