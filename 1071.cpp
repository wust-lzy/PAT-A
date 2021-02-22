#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
字符串统计单词数  用map处理。
坑点就是 必须字符串长度大于0的才统计
*/
int main()
{
    map<string, int> book;
    string s,temp;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
    {
        if(isalnum(s[i]))
        {
            temp += tolower(s[i]);
        }
        if (!isalnum(s[i])||i==s.size()-1)
        {
            if(temp.size()!=0)
            {
                book[temp]++;
                // cout << temp << endl;
            }
            temp = "";
        }
    }
    int maxn = -1;
    for (auto it = book.begin(); it!=book.end(); it++)
    {
        if(it->second>maxn)
        {
            maxn = it->second;
            temp = it->first;
        }
    }
    cout << temp << " " << book[temp];
    return 0;
}