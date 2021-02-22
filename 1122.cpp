#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
哈密尔顿图的判定
图的哈密顿圈是指包含图的所有顶点的圈。
类似地，包含图的所有顶点的路称为图的哈密顿路（Hamilton path）。
一个图若包含哈密顿圈，则称这个图为哈密顿图（Hamiltonian graph）
*/
int e[205][205];
int main()
{
    memset(e, 0, sizeof(e));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        e[a][b] = e[b][a] = 1;
    }
    int q, k;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int flag = 1;
        cin >> k;
        vector<int>v(k);
        unordered_set<int> s;
        for (int j = 0; j < k;j++)
        {
            cin >> v[j];
            s.insert(v[j]);
        }
        if(s.size()!=n||v[0]!=v[k-1]||k!=n+1)
            flag = 0;
        else
        {
            for (int j = 0; j < k - 1;j++)
            {
                if(!e[v[j]][v[j+1]])
                {
                    flag = 0;
                    break;
                }
            }
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}