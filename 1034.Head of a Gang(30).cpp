#include<bits/stdc++.h>
using namespace std;
map<int, string> inttostr;
map<string, int> strtoint;
map<string, int> ans;
int idnum = 1, k;
int sto(string s)
{
    if(strtoint[s]==0)
    {
        strtoint[s] = idnum;
        inttostr[idnum] = s;
        return idnum++;
    }
    else
    {
        return strtoint[s];
    }
}
int g[2010][2010], weight[2010];
bool vis[2010];
void dfs(int u,int &head,int &num,int &total)
{
    vis[u] = 1;
    num++;
    if(weight[u]>weight[head])
        head = u;
    for (int v = 1; v < idnum;v++)
    {
        if(g[u][v]>0)
        {
            total += g[u][v];
            g[u][v] = g[v][u] = 0;
            if(!vis[v])
            {
                dfs(v, head, num, total);
            }
        }
    }
}
void dfstrave()
{
    for(int i=1;i < idnum;i++)
    {
        if(!vis[i])
        {
            int head = i, num = 0, total = 0;
            dfs(i, head, num, total);
            if(num>2&&total>k)
            {
                ans[inttostr[head]] = num;
            }
        }
    }
}
int main()
{
    int n, w;
    cin >> n >> k;
    string s1, s2;
    for (int i = 0; i < n;i++)
    {
        cin >> s1 >> s2 >> w;
        int id1 = sto(s1);
        int id2 = sto(s2);
        weight[id1] += w;
        weight[id2] += w;
        g[id1][id2] += w;
        g[id2][id1] += w;
    }
    dfstrave();
    cout << ans.size() << endl;
    for (auto it = ans.begin(); it != ans.end();it++)
    {
        cout << it->first << " " << it->second << endl;
    }
        return 0;
}