#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
树的遍历
*/
const int maxn = 110;
struct node
{
    int weight;
    vector<int> child;
} book[maxn];
bool cmp(int a,int b)
{
    return book[a].weight > book[b].weight;
}
int n, m, s;//节点数，边数，给定的和
int path[maxn];
void dfs(int index,int numnode,int sum)
{
    if(sum>s) //当前和超过s
        return;
    if(sum==s)
    {
        if(book[index].child.size()!=0) //还没到叶子节点，直接返回
            return;
        for (int i = 0; i < numnode;i++)
        {
            printf("%d", book[path[i]].weight);
            if(i!=numnode-1)
                printf(" ");
            else
            {
                printf("\n");
            }
        }
        return;
    }
    for (int i = 0; i < book[index].child.size(); i++) //枚举所有子节点
    {
        int child = book[index].child[i];
        path[numnode] = child;
        dfs(child, numnode + 1, sum + book[child].weight);
    }
}
int main()
{
    scanf("%d%d%d", &n, &m, &s);
    for (int  i = 0; i < n; i++)
    {
        scanf("%d", &book[i].weight);
    }
    int id, k, child;
    for (int i = 0; i < m;i++)
    {
        scanf("%d%d", &id, &k); //结点编号，孩子个数
        for (int j = 0; j < k;j++)
        {
            scanf("%d", &child);   //child为结点id的孩子
            book[id].child.push_back(child);
        }
        sort(book[id].child.begin(), book[id].child.end(), cmp);
    }
    path[0] = 0;   //路径的第一个结点设置为0号结点
    dfs(0, 1, book[0].weight);
    return 0;
}