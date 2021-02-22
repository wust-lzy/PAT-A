#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
unordered_map 记录不兼容的数字和出现的数字
然后判断即可
*/
unordered_map<int, vector<int> > book;
int main()
{
    int n, m,k;
    cin >> n >> m;
    for (int i = 0; i < n;i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        book[a].push_back(b);
        book[b].push_back(a);
    }
    for (int i = 0; i < m;i++)
    {
        scanf("%d", &k);
        unordered_map<int, int> vis;
        vector<int> v(k);
        for (int j = 0; j < k;j++)
        {
            scanf("%d", &v[j]);
            vis[v[j]] = 1;
        }
        int flag = 1;
        for (int j = 0; j < k&&flag;j++)
        {
            if(book[v[j]].empty())
                continue;
            for (int x = 0; x < book[v[j]].size();x++)
            {
                int index = book[v[j]][x];
                if(vis[index])
                {
                    flag = 0;
                    break;
                }
            }
        }
        printf("%s\n", flag ? "Yes" : "No");
    }
        return 0;
}