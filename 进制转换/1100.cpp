#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
13进制转换 判断的条件非常多
坑点就是 被13整除时 不用输出0
*/
string book[2][13] = {{"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"},
                      {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"}};
void fun1(int n)
{
    if (n > 12)
    {
        if (n%13==0)
        {
            cout << book[1][n / 13]<<endl;
        }
        else
        {
            cout << book[1][n / 13] << " " << book[0][n % 13] << endl;
        }
    }
    else
    {
        cout << book[0][n] << endl;
    }
}
void fun2(string s)
{
    int len = s.length(), ans = 0;
    if (len > 4)
    {
        int a, b;
        string s1 = s.substr(0, 3), s2 = s.substr(4, 3);
        for (int i = 0; i < 13; i++)
        {
            if (book[1][i] == s1)
                a = i;
            if (book[0][i] == s2)
                b = i;
        }
        ans = a * 13 + b;
    }
    else
    {
        int flag = 0;
        for (int i = 0; i < 13; i++)
        {
            if (book[0][i] == s)
            {
                ans = i;
                flag = 1;
                break;
            }
        }
        if (!flag) //没找到
        {
            for (int i = 0; i < 13; i++)
            {
                if (book[1][i] == s)
                {
                    ans = 13 * i;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    int n;
    string s;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++)
    {
        getline(cin, s);

        if (isdigit(s[0]))
        {
            fun1(stoi(s));
        }
        else
        {
            fun2(s);
        }
    }
    return 0;
}