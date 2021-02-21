#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
判断给定序列是否为拓扑序列
用领接表存储有向图
用一个数组记录每个结点的入度
从给定序列的第一个结点开始遍历
判断是否入度为0，如果是，从这个结点出发，到达的每个结点的入度--
否则 这个序列就不是拓扑序列
*/
int main()
{
    int n, m,k;
    cin >> n >> m;
    vector<int> in(n + 1);
    vector<int> e[n+1];
    for (int i = 0; i < m;i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        e[a].push_back(b);
        in[b]++;
    }
    cin >> k;
    vector<int> ans;
    for (int i = 0; i < k;i++)
    {
        int flag = 1,fir=1;
        vector<int> temp(n);
        for (int j = 0; j < n;j++)
            scanf("%d", &temp[j]);
        vector<int> vis(in); //入度结点数组复制一份  因为要查询k次
        for (int j = 0; j < n;j++)
        {
            if(vis[temp[j]]!=0)
            {
                flag = 0;
                break;
            }
            for (int x = 0; x < e[temp[j]].size();x++)//遍历当前节点，将出度结点的入度--
                vis[e[temp[j]][x]]--;
        }
        if(!flag)
            ans.push_back(i);
    }
    for (int i = 0; i < ans.size();i++)
    {
        printf("%d", ans[i]);
        if(i!=ans.size()-1)
            printf(" ");
    }
    return 0;
}