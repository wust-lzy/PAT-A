#include <bits/stdc++.h>
using namespace std;
/*
用数组标记数字是不是出现了
可以直接判定没找到情况
遍历数组  找到符合情况直接退出
不懂的地方就是为什么从头开始遍历就一定是最低的公共祖先呢？
*/
int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> book(n);
    unordered_map<int, int> vis;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &book[i]);
        vis[book[i]] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        if (!vis[u] || !vis[v]) //不存在
        {
            if (vis[u] && !vis[v])
                printf("ERROR: %d is not found.\n", v);
            else if (!vis[u] && vis[v])
                printf("ERROR: %d is not found.\n", u);
            else
                printf("ERROR: %d and %d are not found.\n", u, v);
        }
        else
        {
            int ans;
            for (int j = 0; j < n; j++)
            {
                if (book[j] == u||book[j]==v||(book[j] > v && book[j] < u)||(book[j] > u && book[j] < v))
                {
                    ans = book[j];
                    break;
                }
            }
            if(ans==u||ans==v)
                printf("%d is an ancestor of %d.\n",ans, ans == u ? v : u);
            else
                printf("LCA of %d and %d is %d.\n", u, v, ans);
        }
    }
    return 0;
}