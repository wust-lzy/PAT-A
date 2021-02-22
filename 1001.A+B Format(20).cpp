#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
字符串处理
每3位加一个逗号
*/
int main()
{
    ll a, b, sum;
    stack<char> s;
    cin >> a >> b;
    sum = a + b;
    if (!sum)
    {
        cout << sum;
        return 0;
    }
    if (sum < 0)
    {
        cout << "-";
        sum = abs(sum);
    }
    int cnt = 0;
    while (sum)
    {
        cnt++;
        s.push(sum % 10 + '0');
        sum /= 10;
        if (cnt == 3 && sum)
        {
            s.push(',');
            cnt = 0;
        }
    }
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    return 0;
}