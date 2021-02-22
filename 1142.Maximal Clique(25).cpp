#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
先判断是否是clique，即判断是否任意两边都相连；
之后判断是否是maximal，即遍历所有不在集合中的剩余的点，
看是否存在一个点满足和集合中所有的结点相连，最后如果都满足，
那就输出Yes表示是Maximal clique～
*/
int g[205][205];
bool clique(vector<int>&v)
{
    int len = v.size();
    for (int i = 0; i < len;i++)
        for (int j = i; j < len;j++)
        {
            if(!g[v[i]][v[j]])
                return 0;
        }
    return 1;
}
int main()
{
    memset(g, 0, sizeof(g));
    for (int i = 1; i <= 200;i++)
        g[i][i] = 1;
    int n, m, a, b, k;
    cin >> n >> m;
    int vis[n + 1] = {0};
    for (int i = 0; i < m;i++)
    {
        scanf("%d %d", &a, &b);
        g[a][b] = g[b][a] = 1;
    }
    scanf("%d", &k);
    for (int i = 0; i < k;i++)
    {
        memset(vis, 0, sizeof(vis));
        int v,t;
        scanf("%d", &v);
        vector<int> temp;
        for (int j = 0; j < v;j++)
        {
            scanf("%d", &t);
            temp.push_back(t);
            vis[t] = 1;
        }
        if(!clique(temp))
            printf("Not a Clique\n");
        else
        {
            int flag = 1;
            for (int j = 1; j <= n;j++)
            {
                if(!vis[j])
                {
                    temp.push_back(j);
                    if(clique(temp))
                    {
                        flag = 0;
                        break;
                    }
                    temp.pop_back();
                }
            }
            printf("%s\n", flag ? "Yes" :"Not Maximal" );
        }
    }
    return 0;
}