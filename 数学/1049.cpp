#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
暴力法  会超时  不过也得了22分
数学方法，1的总数等于每个  个位出现1的次数的累加和
int fun(ll n)
{
    int cnt = 0;
    while(n)
    {
        if(n%10==1)
            cnt++;
        n /= 10;
    }
    return cnt;
}
int main()
{
    ll n;
    ll sum = 0;
    cin >> n;
    for (int i = 1;i<=n;i++)
    {
        sum += fun(i);
    }
    printf("%lld\n", sum);
    return 0;
}
*/
int main()
{
    ll n;
    scanf("%lld", &n);
    ll a = 1, left, right, now = 1, ans = 0;
    while(n/a)
    {
        left = n / (a * 10);
        now = n / a % 10;
        right = n % a;
        if(now==0)
            ans += left * a;
        else if(now==1)
            ans += left * a + right + 1;
        else if (now > 1)
            ans += (left + 1) * a;
        a *= 10;
    }
    printf("%lld\n", ans);
    return 0;
}