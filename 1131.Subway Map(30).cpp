#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 10010;
const int inf = 1e9;
int n,m, last;
bool vis[maxn];
vector<vector<int> >v(maxn);
unordered_map<int, int> line;
vector<int> path;
int minDist = inf;
int transfer = inf;
struct node
{
    int id=0, dist=0, sum=0, nowline=0;
    vector<int> path;
    bool operator <(const node &x)const{
        if(dist!=x.dist)
            return x.dist < dist;
        else
            return x.sum < sum;
    }
};
void bfs(int s)
{
    node temp;
    temp.id = s;
    vis[s] = 1;
    priority_queue<node> q;
    q.push(temp);
    while(!q.empty())
    {
        node now = q.top();
        now.path.push_back(now.id);
        vis[now.id] = 1;
        if(now.id==last)
        {
            path = now.path;
            minDist = now.dist;
            break;
        }
        for (int i = 0; i < v[now.id].size();i++){
            if(!vis[v[now.id][i]]){
                node nn;
                nn.id = v[now.id][i];
                nn.path = now.path;
                nn.dist = now.dist + 1;
                nn.nowline = line[now.id * 10000 + nn.id];
                nn.sum = now.sum;
                if (now.nowline != 0 && nn.nowline != now.nowline)
                    nn.sum++;
                q.push(nn);
            }
        }
        q.pop();
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n;i++)
    {
        int sum, t1, t2;
        cin >> sum >> t1;
        for (int j = 1; j < sum;j++)
        {
            cin >> t2;
            v[t1].push_back(t2);
            v[t2].push_back(t1);
            line[t1 * 10000 + t2] = line[t2 * 10000 + t1] = i;
            t1 = t2;
        }
    }
    cin >> m;
    for (int k = 0; k < m;k++)
    {
        int a;
        scanf("%d %d", &a, &last);
        path.clear();
        fill(vis, vis + maxn, false);
        bfs(a);
        printf("%d\n", minDist);
        int now = line[path[0] * 10000 + path[1]];
        int i = 0, j;
        for (j = 1; j < path.size();j++)
        {
            if(line[path[j-1]*10000+path[j]]!=now){
                printf("Take Line#%d from %04d to %04d.\n",now,path[i],path[j-1]);
                i=j-1;
                now=line[path[j-1]*10000+path[j]];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n",now,path[i],path[j-1]);
    }
    return 0;
}