#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
字符串处理
非常麻烦
有两个测试点过不了  尚未解决
*/
int main()
{
    int k;
    string s;
    map<char, int> book;
    cin >> k;
    getchar();
    getline(cin, s);
    int len = s.length();
    int i = 0;
    while(1)
    {
        if (i>=len)
        {
            break;
        }
        int cnt = 1;
        for (int j = 1; j + i < len;j++)
        {
            if (s[i]==s[j+i])
            {
                cnt++;
            }
            else
            {
                break;
            }
        }
        book[s[i]] = cnt % k == 0 ? 1 : 0;
        i += cnt;
    }
    for (auto it = book.begin(); it != book.end(); it++)
    {
        if (it->second)
        {
            cout << it->first;
        }
    }
    cout << endl;
    for (i = 0; i < len; )
    {
        cout << s[i];
        book[s[i]] ? i += k : i++;
    }
    return 0;
}
