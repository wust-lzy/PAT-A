#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    vector<int> son;
};
int cnt = 0, min_level = 1e9;
vector<node> v;
void dfs(int index,int depth)
{
    if(min_level<depth)
        return;
    if (v[index].son.empty())
    {
        if (depth<min_level)
        {
            cnt = 1;
            min_level = depth;
        }
        else if(min_level==depth)
            cnt++;
    }
    for (int i = 0; i < v[index].son.size(); i++)
    {
        dfs(v[index].son[i], depth + 1);
    }
}
int main()
{
    int n;
    double p, r;
    cin >> n >> p >> r;
    r /= 100;
    v.resize(n);
    for (int  i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        if (k!=0)
        {
            for (int j = 0; j < k; j++)
            {
                int t;
                cin >> t;
                v[i].son.push_back(t);
            }
        }
    }
    dfs(0, 0);
    printf("%.4lf %d", pow(1 + r, min_level) * p, cnt);
    return 0;
}