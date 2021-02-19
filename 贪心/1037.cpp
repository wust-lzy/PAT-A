#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int nc, np, p = 0, q = 0;
    ll ans = 0;
    scanf("%d", &nc);
    vector<int> v1(nc);
    for (int i = 0; i < nc;i++)
        scanf("%d", &v1[i]);
    scanf("%d", &np);
    vector<int> v2(np);
    for (int i = 0; i < np;i++)
        scanf("%d", &v2[i]);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    while(p<nc&&q<np&&v1[p]<0&&v2[q]<0)
    {
        ans += v1[p++] * v2[q++];
    }
    p = nc - 1, q = np - 1;
    while(p>=0&&q>=0&&v1[p]>0&&v2[q]>0)
    {
        ans += v1[p--] * v2[q--];
    }
    cout << ans << endl;
    return 0;
}