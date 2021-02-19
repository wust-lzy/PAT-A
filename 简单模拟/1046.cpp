#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
模拟，输入的时候做求和处理，不然输出的时候会超时
*/
int main()
{
    int n, m;
    ll sum = 0;
    cin >> n;
    vector<ll> dis(n+1);
    for (int i = 1; i <= n;i++)
    {
        int p;
        scanf("%d", &p);
        sum += p;
        dis[i] = sum;
    }
    cin >> m;
    for (int i = 0; i < m;i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if(a>b)
        {
            int t = a;
            a = b;
            b = t;
        }
        ll temp = dis[b - 1] - dis[a - 1];
        printf("%lld\n", min(temp, sum - temp));
    }
        return 0;
}