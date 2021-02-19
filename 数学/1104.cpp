#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
将数列中的每个数字读取到temp中，
假设我们选取的片段中包括temp，
且这个片段的首尾指针分别为p和q，
那么对于p，有i种选择，即12…i，对于q，
有n-i+1种选择，即i, i+1, … n，
所以p和q组合形成的首尾片段有i * (n-i+1)种
*/
int main()
{
    int n;
    cin >> n;
    ll ans = 0;
    double t;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf", &t);
        ans += (ll)(t * 1000) * i * (n - i + 1);
    }
    printf("%.2f", ans / 1000.0);
    return 0;
}