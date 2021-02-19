#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
数的层序遍历
dfs 统计每层的个数  输出最大的个数和最大个数所在的层数
*/
vector<int> v[105];
int level[105];
void dfs(int index,int depth)
{
    level[depth]++;
    if (v[index].empty())
    {
        return;
    }
    for (int i = 0; i < v[index].size(); i++)
    {
        dfs(v[index][i], depth + 1);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int index, son, k;
        cin >> index >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> son;
            v[index].push_back(son);
        }
    }
    dfs(1, 1);
    int max_level=-1, max_num=-1;
    for (int i = 1; i < 100; i++)
    {
        if (level[i]>max_num)
        {
            max_num = level[i];
            max_level = i;
        }
    }
    cout << max_num << " " << max_level;
    return 0;
}