#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll convert(string s,ll radix) //将radix进制的s转换成10进制
{
    ll sum = 0;
    int t, index = 0;
    for (auto it = s.rbegin(); it != s.rend(); it++)
    {
        t = isdigit(*it) ? *it - '0' : *it - 'a' + 10;
        sum += t * pow(radix, index++);
    }
    return sum;
}
//二分法，找到是否有一种进制，能够让s等于sum
ll find_radix(string s,ll num)
{
    char it = *max_element(s.begin(), s.end());
    ll low = (isdigit(it) ? it - '0' : it - 'a' + 10) + 1;
    ll high = max(num, low);
    while(low<=high)
    {
        ll mid = low + (high - low) / 2; //进制
        ll t = convert(s, mid);
        if(t<0||t>num)
            high = mid - 1;
        else if(t==num)
        {
            return mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
int main()
{
    string s1, s2;
    ll tag, radix, ans;
    cin >> s1 >> s2 >> tag >> radix;
    if(tag==1)
        ans = find_radix(s2, convert(s1, radix));
    else
    {
        ans = find_radix(s1, convert(s2, radix));
    }
    if(ans!=-1)
        cout << ans;
    else
    {
        cout << "Impossible";
    }
    //cout << convert("110", 2);
    return 0;
}
