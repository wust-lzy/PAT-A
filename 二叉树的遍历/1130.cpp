#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    string data;
    int left, right;
};
vector<node> v;
int root;
int vis[100];
string dfs(int index)
{
    if(index==-1)
        return "";
    if(v[index].right!=-1)
    {
        v[index].data = dfs(v[index].left) + v[index].data + dfs(v[index].right);
        if(index!=root)
            v[index].data = "(" + v[index].data + ")";
    }
    return v[index].data;
}
int main()
{
    string t;
    int n;
    cin >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].data >> v[i].left >> v[i].right;
        if(v[i].left!=-1)
            vis[v[i].left] = 1;
        if(v[i].right!=-1)
            vis[v[i].right] = 1;
    }
    for (int i = 1; i <= n;i++)
    {
        if(!vis[i])
        {
            root = i;
            break;
        }
    }
    string ans=dfs(root);
    cout << ans;
    return 0;
}