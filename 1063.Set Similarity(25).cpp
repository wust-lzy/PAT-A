#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
求集合的交集和并集元素个数
*/
int main()
{
    int n, m, k;
    scanf("%d", &n);
    vector<set<int> > v(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        for (int j = 0; j < m;j++)
        {
            int t;
            scanf("%d", &t);
            v[i].insert(t);
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        int nc = 0,nt = v[b - 1].size();
        for (auto it = v[a-1].begin(); it !=v[a-1].end(); it++)
        {
            if(v[b-1].find(*it)!=v[b-1].end()) //交集
            {
                nc++;
            }
            else  //a中元素b没有
            {
                nt++;
            }
        }
        printf("%.1lf%\n", nc * 100.0 / (nt * 1.0));
    }
    
    return 0;
}