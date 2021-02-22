#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
科学计数法   分情况讨论
*/
string s;
void func()
{
    int index;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]=='E')
        {
            index = i;
            break;
        }
    }
    int num = stoi(s.substr(index + 2, s.size() - index-1));//将指数转换为数字
    //cout << stoi(num);
    if(s[index+1]=='-')//负指数
    {
        printf("0.");
        for (int i = 0; i < num-1; i++)
        {
            printf("0");
        }
        printf("%c", s[0]);
        cout << s.substr(2, index - 2);
    }
    else if(s[index+1]=='+')//正指数
    {
        if (num>=index-2)
        {
            printf("%c", s[0]);
            cout << s.substr(2, index - 2);
            for (int i = 0; i < num-(index-2); i++)
            {
                printf("0");
            }
        }
        else //小数点右移num位
        {
            printf("%c", s[0]);
            cout << s.substr(2, num);
            printf(".");
            cout << s.substr(num + 2, index - (num + 2));
        }
        
        
    }
    
}
int main()
{
    cin >> s;
    if (s[0]=='-')
    {
        printf("-");
    }
    s = s.substr(1);
    func();
    return 0;
}