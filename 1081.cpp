#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
分数的加法 两个坑点：
要开ll  约分的时候回爆int
整数部分和小数部分都为0的情况要考虑  不然最后一个点过不了
尚未考虑分母为0的情况，不过也ac了
*/
ll gcd(ll a, ll b)
{
    return a % b == 0 ? b : gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}
int main()
{
    ll n, numerator[110], denominator[110];
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld/%lld", &numerator[i], &denominator[i]);
    }
    for (ll i = 1; i < n; i++)
    {
        ll fm = lcm(denominator[i], denominator[i - 1]);
        numerator[i] = numerator[i] * (fm / denominator[i]) + numerator[i - 1] * (fm / denominator[i - 1]);
        denominator[i] = fm;
    }
    ll g = gcd(numerator[n - 1], denominator[n - 1]);
    if (denominator[n - 1] != g)
    {
        numerator[n - 1] /= g;
        denominator[n - 1] /= g;
    }
    ll ans1 = numerator[n - 1] / denominator[n - 1], ans2 = numerator[n - 1] % denominator[n - 1];
    ll flag = 0;
    if (ans1 != 0)
    {
        printf("%lld", ans1);
        flag = 1;
    }
    if (ans2 != 0)
    {
        if (flag)
        {
            printf(" ");
        }
        printf("%lld/%lld", ans2, denominator[n - 1]);
    }
    if (ans1==0&&ans2==0)
    {
        cout << 0 << endl;
    }
    return 0;
}