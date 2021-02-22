#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k;
bool vis[1005];
int book[1005][1005];
void dfs(int index)
{
    vis[index] = 1;
    for (int i = 1; i <= n; i++)
        if (!vis[i] && book[index][i])
            dfs(i);
}
int main()
{
    cin >> n >> m >> k;
    fill(book[0], book[0] + 1005 * 1005, 0);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        book[a][b] = book[b][a] = 1;
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     memset(vis, 0, sizeof(vis));
    //     int cnt = 0;
    //     if (!vis[i])
    //     {
    //         dfs(i);
    //         cnt++;
    //     }
    //     cout << cnt << endl;
    // }
    for (int i = 1; i <= k;i++)
    {
        memset(vis, 0, sizeof(vis));
        int t;
        cin >> t;
        vis[t] = 1;
        int cnt = 0;//
        for (int j = 1; j <= n;j++)
        {
            if(!vis[j])
            {
                dfs(j);
                cnt++;
            }
        }
        cout << cnt - 1 << endl;
    }
    return 0;
}