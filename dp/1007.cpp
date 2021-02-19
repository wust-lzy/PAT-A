#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
最大连续子序列和
在线更新法
*/
int main()
{
    int v[10001];
    ll k;
    cin >> k;
    ll lindex = 0, rindex = k - 1, sum = -1, temp = 0, tindex = 0;
    for (int i = 0; i < k;i++)
    {
        cin >> v[i];
        temp += v[i];
        if(temp<0)
        {
            temp = 0;
            tindex = i + 1;
        }
        else if(temp>sum)
        {
            lindex = tindex;
            sum = temp;
            rindex = i;
        }
    }
    if(sum<0)
        sum = 0;
    cout << sum << " " << v[lindex] << " " << v[rindex];
    return 0;
}