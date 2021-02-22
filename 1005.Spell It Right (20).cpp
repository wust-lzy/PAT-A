#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
简单题
字符串处理求和
*/
int main()
{
    string s;
    map<int, string> m;
    stack<string> ans;
    m[0]=("zero");
    m[1]=("one");
    m[2]=("two");
    m[3]=("three");
    m[4]=("four");
    m[5]=("five");
    m[6]=("six");
    m[7]=("seven");
    m[8]=("eight");
    m[9]=("nine");
    ll sum = 0;
    cin >> s;
    for (unsigned int i = 0; i < s.length();i++)
        sum += s[i] - '0';
    if(!sum)
    {
        cout << "zero";
        return 0;
    }
    while(sum)
    {
        ans.push(m[sum % 10]);
        sum /= 10;
    }
    cout << ans.top();
    ans.pop();
    while(!ans.empty())
    {
        cout << " " << ans.top();
        ans.pop();
    }
    return 0;
}