#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
并查集
每个人有公共的爱好的为一个集合
统计集合的个个数  并将集合排序
*/
int father[1000];
int isroot[1000] = {0};
int course[1000] = {0};
int findfather(int x)
{
    if(x==father[x])
        return x;
    else
    {
        int f = findfather(father[x]);
        father[x] = f;
        return f;
    }
    
}
void Union(int a,int b)
{
    int faa = findfather(a);
    int fab = findfather(b);
    if (faa!=fab)
    {
        father[faa] = fab;
    }
}
void init(int n)
{
    for (int i = 1; i <=n; i++)
    {
        father[i] = i;
        isroot[i] = 0;
    }
}
bool cmp(int a,int b)
{
    return a > b;
}
int main()
{
    int n,k,h;
    scanf("%d", &n);
    init(n);
    for (int i = 1; i <=n; i++)
    {
        scanf("%d:", &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &h);
            if(course[h]==0)
                course[h] = i;
            Union(i, findfather(course[h]));//合并
        }
    }
    for (int i = 1; i <=n; i++)
    {
        isroot[findfather(i)]++;
    }
    int ans = 0;
    for (int i = 1; i <=n; i++)
    {
        if (isroot[i])
        {
            ans++;
        }
    }
    printf("%d\n", ans);
    sort(isroot + 1, isroot + 1 + n, cmp);
    for (int i = 1; i <=ans; i++)
    {
        cout << isroot[i];
        if (i!=ans)
        {
            cout << " ";
        }
    }
    return 0;
}