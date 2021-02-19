#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(string s)
{
    string t;
    t.assign(s.rbegin(), s.rend());
    return t==s;
}
string add(string s)
{
    int flag = 0;
    string ans;
    ans.assign(s.rbegin(), s.rend());
    for (int i = s.length() - 1; i >= 0;i--)
    {
        int t = (s[i] - '0') + (ans[i] - '0')+flag;
        ans[i] = t % 10 + '0';
        if(t>=10)
        {
            flag = 1;
        }
        else
            flag = 0;
    }
    if(flag)
        ans = '1' + ans;
    return ans;
}
int main()
{
    string s;
    int k;
    int cnt = 0;
    cin >> s >> k;
    while(!check(s)&&cnt<k)
    {
        // cout << n << " "<<check(n)<<endl;
        cnt++;
        s = add(s);
    }
    cout << s << endl
         << cnt;
    return 0;
}