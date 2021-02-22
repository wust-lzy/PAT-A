#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    vector<ll> ans;
    int n, m;
    ll temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &temp);
        ans.push_back(temp);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%lld", &temp);
        ans.push_back(temp);
    }
    sort(ans.begin(), ans.end());
    printf("%lld", ans[(n + m - 1) / 2]);
    return 0;
}