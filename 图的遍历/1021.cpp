#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
给出n个结点（1~n）之间的n条边，问是否能构成一棵树，
如果不能构成则输出它有的连通分量个数，
如果能构成一棵树，输出能构成最深的树的高度时，树的根结点。
如果有多个，按照从小到大输出。
*/
vector<vector<int> > v;
bool vis[10005];
vector<int> temp;
int maxh = -1;
set<int> s;
void dfs(int u,int depth)
{
    vis[u] = 1;
    if(depth>maxh)
    {
        temp.clear();
        maxh = depth;
        temp.push_back(u);
    }
    else if(depth==maxh)
    {
        temp.push_back(u);
    }
    for (int i = 0; i < v[u].size();i++)
    if(!vis[v[u][i]])
        dfs(v[u][i], depth + 1);
}
int main()
{
    int n, a, b, cnt = 0,s1;
    cin >> n;
    v.resize(n + 1);
    for (int i = 0; i < n-1;i++)
    {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n;i++)
    {
        if(!vis[i])
        {
            dfs(i, 1);
            if(i==1)
            {
                if(temp.size()!=0)
                    s1 = temp[0];
                for (int j = 0; j < temp.size();j++)
                    s.insert(temp[j]);
            }
            cnt++;
        }
    }
    // for (auto i = s.begin(); i != s.end();i++)
    //     cout << *i << " ";
    // cout << endl;
    if(cnt==1)
    {
        temp.clear();
        maxh = -1;
        fill(vis, vis + 10005, 0);
        dfs(s1, 1);
        for (int i = 0; i < temp.size();i++)
        {
            // cout << temp[i] << " ";
            s.insert(temp[i]);
        }
        // cout << endl;
        for (auto i = s.begin(); i != s.end();i++)
        cout << *i <<endl;
    }
    else
    {
        cout << "Error: " << cnt << " components";
    }
        return 0;
}