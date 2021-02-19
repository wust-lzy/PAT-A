#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
dfs搜索+剪枝
*/
int n, k, p,maxsum=-1;
vector<int> fac,ans,temp;
int quick_pow(int x,int y)//快速幂 计算x的y次方
{
    int ans = 1;
    while (y)
    {
        if(y&1)
            ans *= x;
        x *= x;
        y >>= 1;
    }
    return ans;
}
void init()
{
    int i = 0,t=0;
    while (t<=n)
    {
        fac.push_back(t);
        i++;
        t = quick_pow(i, p);
    }
}
void dfs(int index,int nowk,int sum,int facsum)
{
    if (sum==n&&nowk==k)
    {
        if (facsum>maxsum)
        {
            ans = temp;
            maxsum = facsum;
        }
        return;
    }
    if (sum>n||nowk>k)
    {
        return;
    }
    if (index>=1)
    {
        temp.push_back(index);
        dfs(index, nowk + 1, sum + fac[index], facsum + index);
        temp.pop_back();
        dfs(index - 1, nowk, sum, facsum);
    } 
}
int main()
{
    
    cin >> n >> k >> p;
    init();
    dfs(fac.size() - 1, 0, 0, 0);
    if (maxsum==-1)
    {
        cout << "Impossible";
        return 0;
    }
    printf("%d = ", n);
    for (int i = 0; i < ans.size(); i++)
    {
        printf("%d^%d", ans[i], p);
        if (i!=ans.size()-1)
        {
            printf(" + ");
        }
        
    }
    // cout << quick_pow(2, 3);
    return 0;
}