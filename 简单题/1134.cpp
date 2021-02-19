#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
验证每条边的两个顶点 是不是都在给的顶点集里面
输出yes or no
一开始用find函数超时了 用哈希ac
*/
int main()
{
    int n, m,k;
    cin >> n >> m;
    vector<pair<int, int> > p;
    int a, b,vis[n];
    for (int i = 0; i < m;i++)
    {
        scanf("%d %d", &a, &b);
        p.push_back(pair<int, int>(a, b));
    }
    scanf("%d", &k);
    for (int i = 0; i < k;i++)
    {
        memset(vis, 0, sizeof(vis));
        int v, flag = 1,t;
        scanf("%d", &v);
        for (int j = 0; j < v;j++)
        {
            scanf("%d", &t);
            vis[t] = 1;
        }
        for (int j = 0; j < m;j++)
        {
            if(!vis[p[j].first]&&!vis[p[j].second])
            {
                flag = 0;
                break;
            }
        }
        printf("%s\n",flag?"Yes":"No");
    }
    return 0;
}