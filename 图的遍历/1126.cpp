#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
dfs遍历图判断连通性
所有顶点的度数都是偶数的连通图是欧拉图
有两个顶点度数是奇数的连通图是半欧拉图
其他的都不是
*/
vector<vector<int> > v;
bool vis[1000];
int cnt = 0;
void dfs(int index)
{
    vis[index] = 1;
    cnt++;
    for (int i = 0; i < v[index].size(); i++)
    {
        if(!vis[v[index][i]])
        {
            dfs(v[index][i]);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    v.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int even = 0;
    for (int i = 1; i <= n;i++)
    {
        printf("%d", v[i].size());
        if (i!=n)
        {
            printf(" ");
        }
        if(v[i].size()%2==0)
            even++;
    }
    printf("\n");
    dfs(1);
    if(even==n&&cnt==n)
        printf("Eulerian\n");
    else if(even==n-2&&cnt==n)
        printf("Semi-Eulerian\n");
    else
        printf("Non-Eulerian\n");
    return 0;
}