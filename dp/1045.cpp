#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
dp  最长不下降子序列问题
首先剔除掉不喜欢的颜色
将每个喜欢的颜色对应的序号记录下来，dp时候判断
*/
int book[201], a[10001], dp[10001];
int main()
{
    int n, m, t, l, cnt = 0, maxn = 0;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &t);
        book[t] = i;
    }
    scanf("%d", &l);
    for (int i = 0; i < l; i++)
    {
        scanf("%d", &t);
        if (book[t] >= 1)
        {
            a[cnt++] = book[t];
        }
    }
    for (int i = 0; i < cnt; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[i] >= a[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxn = max(dp[i], maxn);
    }
    printf("%d\n", maxn);
    return 0;
}