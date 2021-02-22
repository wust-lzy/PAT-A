#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
字符串处理  找到相同的字符串后缀
坑点就是单词不认得 suffix  后缀
*/
int main()
{
    int n;
    cin >> n;
    string temp, ans;
    getchar();
    for (int i = 0; i < n; i++)
    {
        getline(cin, temp);
        reverse(temp.begin(), temp.end());
        if (i==0)
        {
            ans = temp;
        }
        else
        {
            for (int j = 0; j < temp.length() && j < ans.length();j++)
            {
                if (ans[j]!=temp[j])
                {
                    ans = ans.substr(0, j);
                    break;
                }
            }
        }
    }
    reverse(ans.begin(), ans.end());
    if(!ans.empty())
    {
        cout << ans;
    }
    else
    {
        printf("nai");
    }
    
    return 0;
}