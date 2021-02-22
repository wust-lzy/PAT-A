#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n, m,minlost=1e10;
    int left = 0;
    bool flag = 0;
    cin >> n >> m;
    vector<ll> book(n+1);
    for (int i = 1; i <= n;i++)
        scanf("%lld", &book[i]);
    for (int i = 1; i <= n; i++) //求后缀和
    {
        book[i] += book[i - 1];
    }
    for (int i = 1; i <= n;i++)
    {
        while (book[i]-book[left]>m)
        {
            minlost = min(minlost, book[i] - book[left]);
            left++;
        }
        if(book[i]-book[left]==m)
        {
            printf("%lld-%d\n", left + 1, i);
            flag = 1;
        }
    }
    if(!flag)
    {
        // printf("min=%lld\n", minlost);
        left = 0;
        for (int i = 1; i <= n;i++)
        {
            while(book[i]-book[left]>minlost)
                left++;
            if(book[i]-book[left]==minlost)
                printf("%lld-%lld\n", left + 1, i);
        }
    }
        return 0;
}