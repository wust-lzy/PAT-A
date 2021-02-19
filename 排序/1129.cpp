#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int cnt[50001], v[50001], vis[50001];
bool cmp(int a, int b)
{
    if (cnt[a] != cnt[b])
        return cnt[a] > cnt[b];
    else
        return a < b;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &v[i]);
        if (i > 1)
        {
            if (!vis[v[i - 1]])  //不在序列里面
            {
                if (ans.size() < k) //序列没有满
                {
                    ans.push_back(v[i - 1]);
                    vis[v[i - 1]] = 1;
                }
                else //序列已经满了
                {
                    int t = ans[k - 1]; //序列里面的最后一个元素
                    if (cnt[v[i - 1]] > cnt[t])
                    {
                        vis[t] = 0; //出队
                        ans.pop_back();
                        ans.push_back(v[i - 1]);
                        vis[v[i - 1]] = 1;
                    }
                    else if (cnt[v[i - 1]] == cnt[t])
                    {
                        if (v[i - 1] < t)
                        {
                            vis[t] = 0; //出队
                            ans.pop_back();
                            ans.push_back(v[i - 1]);
                            vis[v[i - 1]] = 1;
                        }
                    }
                }
            }
            sort(ans.begin(), ans.end(), cmp);
            printf("%d:", v[i]); //5: 3
            for (int j = 0; j < ans.size(); j++)
            {
                printf(" %d", ans[j]);
            }
            printf("\n");
        }
        cnt[v[i]]++;
    }
    return 0;
}