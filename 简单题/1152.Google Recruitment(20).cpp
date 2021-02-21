#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
简单题  坑点就是 s.length()和l竟然不一样？
自己只得了19分
*/
bool isprime(int x)
{
    if(x<=1)
        return 0;
    for (int i = 2; i * i <= x;i++)
    if(x%i==0)
        return 0;
    return 1;
}
int main()
{
    int l, k;
    string s;
    cin >> l >> k >> s;
    for (int i = 0; i <= l - k;i++)
    {
        string temp = s.substr(i, k);
        if(isprime(stoi(temp)))
        {
            cout << temp;
            return 0;
        }
    }
    cout << "404\n";
    return 0;
}