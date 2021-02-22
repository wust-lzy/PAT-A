#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
暴力法，求子串
*/
bool check(string s)
{
    int len = s.length();
    for (int i = 0; i < len / 2; i++)
    {
        if(s[i]!=s[len-i-1])
            return 0;
    }
    return 1;
}
int main()
{
    string s;
    int maxn = -1;
    getline(cin, s);
    for (int i = 0; i < s.length();i++)
    {
        for (int j = s.length()-1; j >=i&&j-i+1>maxn;j--)
        {
            if(check(s.substr(i, j - i + 1)))
                maxn = j - i + 1;
        }
    }
    cout << maxn;
    return 0;
}