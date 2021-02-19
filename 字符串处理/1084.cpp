#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
简单题
字符串统计
*/
int main()
{
    string a, b;
    vector<char> ans;
    map<char, bool> cnt;
    cin >> a >> b;
    for (int i = 0; i < b.size(); i++)
    {
        if (isalpha(b[i]))
        {
            b[i] = toupper(b[i]);
        }
        cnt[b[i]] = 1;
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (isalpha(a[i]))
        {
            a[i] = toupper(a[i]);
        }
        if (!cnt[a[i]])
        {
            ans.push_back(a[i]);
            cnt[a[i]] = 1;
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        printf("%c", ans[i]);        
    }
    return 0;
}