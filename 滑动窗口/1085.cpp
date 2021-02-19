#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
寻找最长的序列 满足序列中最大值 >=最小值*p
滑动窗口在线更新
*/
int main()
{
    ll n, p;
    int ans = 0, temp = 0;
    cin >> n >> p;
    vector<ll> book(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &book[i]);
    }
    sort(book.begin(), book.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = i+ans; j < n; j++)
        {
            if (book[j]<=book[i]*p)
            {
                temp = j - i + 1;
                if (temp>ans)
                {
                    ans = temp;
                }     
            }
            else
            {
                break;
            }     
        }
    }
    printf("%d", ans);
    return 0;
}