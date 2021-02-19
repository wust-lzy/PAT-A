#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
统计字符个数
map的遍历
*/
string a, b;
map<char,int> m1, m2;
bool func()
{
    for (auto i = m2.begin(); i !=m2.end(); i++)
    {
        if (m1[i->first]< i->second)
        {
            return 0;
        }
        
    }
    return 1;
}
int main()
{
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++)
    {
        m1[a[i]]++;
    }
    for (int i = 0; i < b.size(); i++)
        m2[b[i]]++;
    if (func())
    {
        cout<<"Yes " << a.length() - b.length();
    }
    else
    {
        int ans = 0;
        for (auto i = m2.begin(); i !=m2.end(); i++)
        {
            if (i->second>m1[i->first])
            {
                ans += i->second - m1[i->first];
            }
        }
        cout << "No " << ans;
    }
    
    
    return 0;
}