#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
自己的方法不知道错在哪里 只有19分
柳神的方法很巧妙  统计A左边P的个数 统计A右边T的个数
每遇到一个A  左边P*右边T  全部相加即为答案~
*/
int main()
{
    const int mod = 1000000007;
    string s;
    cin >> s;
    int cnt_p = 0, cnt_t = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i]=='T')
        {
            cnt_t++;
        }
    }
    ll ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i]=='P')
        {
            cnt_p++;
        }
        else if (s[i]=='A')
        {
            ans = (ans + cnt_p * cnt_t) % mod;
        }
        else if (s[i]=='T')
        {
            cnt_t--;
        }    
    }
    cout << ans;
    return 0;
}