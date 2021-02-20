#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    string id, school;
    int score,rank;
};

bool cmp(node a,node b)
{
    if(a.g!=b.g)
        return a.g > b.g;
    else
        return a.id < b.id;
}
int main()
{
    vector<node> ans;
    unordered_map<string, node> book;
    unordered_map<string, int> vis;
    int n, p, m, cnt = 0,temp;
    cin >> n >> p >> m;
    string t;
    for (int i = 0; i < n;i++)
    {
        cin >> t >> temp;
        vis[t] = 1;
        book[t] = node(t, temp, -1, -1, -1);
    }
    for (int i = 0; i < p;i++)
    {
        cin >> t >> temp;
        if(!vis[t])
        {
            vis[t] = 1;
            book[t] = node(t,-1,temp,-1,-1);
        }
        else
            book[t].gmid = temp;
    }
    for (int i = 0; i < m;i++)
    {
        cin >> t >> temp;
        if(!vis[t])
        {
            vis[t] = 1;
            book[t] = node(t,-1,-1,temp,-1);
        }
        else
            book[t].gfinal = temp;
    }
    for (auto it = book.begin(); it != book.end();it++)
    {
        if(it->second.online>=200)
        {
            if(it->second.gmid>it->second.gfinal)
                it->second.g = round(it->second.gmid * 0.4 + it->second.gfinal * 0.6);
            else
                it->second.g = it->second.gfinal;
            if(it->second.g>=60)
                ans.push_back(it->second);
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); i++)
        printf("%s %d %d %d %d\n", ans[i].id.c_str(), ans[i].online, ans[i].gmid, ans[i].gfinal, ans[i].g);
    return 0;
}