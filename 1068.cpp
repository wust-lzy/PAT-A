#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
01背包问题
因为要输出从小到大的排列，可以先把硬币面额从大到小排列
然后用bool类型的choice[i][j]数组dp[i][j]是否选取
如果选取了就令choice为true,然后进行01背包问题求解
如果最后求解的结果不是恰好等于所需要的价值的，就输出No Soultion，
否则从choice[i][j]判断选取的情况，
i从n到1表示从后往前看第i个物品的选取情况，
j从m到0表示从容量m到0是否选取(j = j – w[i])
*/
bool choice[10010][110];//记录每件物品是不是选了
int w[10010],dp[101];
bool cmp(int a,int b)
{
    return a > b;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
    }
    sort(w + 1, w + 1 + n,cmp);
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= w[i];j--)
        {
            if(dp[j]<=dp[j-w[i]]+w[i])
            {
                choice[i][j] = 1;
                dp[j] = dp[j - w[i]] + w[i];
            }
        }
    }
    if(dp[m]!=m)
    {
        printf("No Solution\n");
    }
    else
    {
        int v = m, index = n,first=0;
        while (v>0)
        {
            if (choice[index][v])
            {
                if(first)
                printf(" %d", w[index]);
                else
                {
                    printf("%d", w[index]);
                    first = 1;
                }
                v -= w[index];
            }
            index--;
        }
    }
    
    return 0;
}