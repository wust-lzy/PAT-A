#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
因为所有长度都要串在一起，
每次都等于(旧的绳子长度+新的绳子长度)/2，
所以越是早加入绳子长度中的段，越要对折的次数多，
所以既然希望绳子长度是最长的，就必须让长的段对折次数尽可能的短。
所以将所有段从小到大排序，然后从头到尾从小到大分别将每一段依次加入结绳的绳子中，
最后得到的结果才会是最长的结果～
*/
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    int ans = v[0];
    for (int i = 1; i < n;i++)
    {
        ans += v[i];
        ans /= 2;
    }
    cout << ans;
    return 0;
}