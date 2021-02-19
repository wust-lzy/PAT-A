#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
结构体按条件排序
德才论
*/
int n, l, h;
struct person
{
    int id, v, t;
    person(int a,int b,int c):id(a),v(b),t(c){}
};
bool cmp(person a,person b)
{
    if((a.v+a.t)!=(b.t+b.v))
    {
        return a.v + a.t > b.t + b.v;
    }
    else
    {
        if(a.v!=b.v)
        {
            return a.v > b.v;
        }
        else
        {
            return a.id < b.id;
        }
        
    }
    
}
int main()
{
    int id,v,t;
    vector<person> ans[4];
    scanf("%d%d%d", &n, &l, &h);
    for (int i = 0; i < n;i++)
    {
        scanf("%d%d%d", &id, &v, &t);
        if(v>=h&&t>=h) //圣人
        {
            ans[0].push_back(person(id, v, t));
        }
        else if(v>=h&&t>=l&&t<h)//君子
        {
            ans[1].push_back(person(id, v, t));
        }
        else if(t>=l&&t<h&&v>=l&&v<h&&v>=t)//愚人
        {
            ans[2].push_back(person(id, v, t));
        }
        else if(t>=l&&v>=l) //小人
        {
            ans[3].push_back(person(id, v, t));
        }
    }
    for (int i = 0; i < 4;i++)
        sort(ans[i].begin(), ans[i].end(), cmp);
    printf("%d\n", ans[0].size() + ans[1].size() + ans[2].size() + ans[3].size());
    for (int i = 0; i < 4;i++)
    {
        for (int j = 0; j < ans[i].size();j++)
        {
            printf("%d %d %d\n", ans[i][j].id, ans[i][j].v, ans[i][j].t);
        }
    }
    return 0;
}