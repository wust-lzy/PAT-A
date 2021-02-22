#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int cnt = 0;
int num[100];
bool f()
{
    for (int i = 0; i < cnt / 2;i++)
    {
        if(num[i]!=num[cnt-i-1])
            return 0;
    }
    return 1;
}
void tentox(int n,int d) //10进制转换成d进制，保存在数组
{
    do
    {
        num[cnt++] = n % d;
        n /= d;
    } while (n);
}
int main()
{
    ll n;
    int b;
    cin >> n >> b;
    tentox(n, b);
    if(f())
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    cout << num[cnt-1];
    for (int i = cnt-2; i >=0;i--)
        cout << " " << num[i];
        return 0;
}
