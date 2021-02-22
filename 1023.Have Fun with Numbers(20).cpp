#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int num1[10],num2[10],cnt=0,num[25];
bool f()
{
    for (int i = 0; i < 10;i++)
    if(num1[i]!=num2[i])
        return 0;
    return 1;
}
int main()
{
    string temp = "";
    int flag = 0;//进位的数
    fill(num2, num2 + 10, 0);
    fill(num1, num1 + 10, 0);
    string s;
    cin >> s;
    for (int i = 0; i < s.size();i++)
    {
        num[cnt++] = s[i] - '0';
        num1[s[i] - '0']++;
    }
    for (int i = cnt-1; i >=0;i--)
    {
        int t = num[i] * 2+flag;
        num2[t % 10]++;
        temp += t % 10 + '0';
        if(t>=10)
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
        if(i==0)
        {
            if(t>=10)
            {
                num2[1]++;
                temp += '1';
            }
        }
    }
    if(f())
        cout << "Yes\n";
    else
    {
        cout << "No\n";
    }
    reverse(temp.begin(), temp.end());
    cout << temp;
    return 0;
}