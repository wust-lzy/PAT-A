#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
整理好逻辑关系就好了
先判断是否连通，不连通就是not a ts cycle
然后判断是否遍历所有城市和形成圈
最后在simple cycle和cycle里面判断
*/
int e[205][205];
const int inf = 1e7;
int main()
{
    int n, m, k, index = -1, ans = inf;
    cin >> n >> m;
    fill(e[0], e[0] + 205 * 205, inf);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        scanf("%d", &e[a][b]);
        e[b][a] = e[a][b];
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int num, total = 0;
        scanf("%d", &num);
        vector<int> v(num);
        unordered_set<int> s;
        for (int j = 0; j < num; j++)
        {
            scanf("%d", &v[j]);
            s.insert(v[j]);
        }
        int flag = 1; //判断连通性
        for (int j = 0; j < num - 1; j++)
            total += e[v[j]][v[j + 1]];
        if (total>=inf) //不连通
            printf("Path %d: NA (Not a TS cycle)\n", i + 1);
        else if(s.size()<n||v[0]!=v[num-1]) //没有遍历所有城市或者不形成圈
            printf("Path %d: %d (Not a TS cycle)\n", i + 1, total);
        else
        {
            if(num==n+1)
                printf("Path %d: %d (TS simple cycle)\n", i + 1, total);
            else
                printf("Path %d: %d (TS cycle)\n", i + 1, total);
            if(total<ans)
            {
                ans = total;
                index = i;
            }
        }
    }
    printf("Shortest Dist(%d) = %d", index + 1, ans);
    return 0;
}