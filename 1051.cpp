#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
模拟栈操作，从1~n入栈，如果栈顶和数组的元素相等，就出栈
如果超时栈的范围 就break
*/
int main()
{
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    for (int i = 0; i < k;i++)
    {
        int now = 0;
        bool flag = 0;
        stack<int> s;
        vector<int> book(n);
        for (int j = 0; j < n;j++)
            scanf("%d", &book[j]);
        for (int j = 0; j < n;j++)
        {
            s.push(j+1);
            if(s.size()>m)
                break;
            while(!s.empty()&&s.top()==book[now])
            {
                s.pop();
                now++;
            }
        }
        if(now==n)
            flag = 1;
        if(flag)
            cout << "YES\n";
        else
        {
            cout << "NO\n";
        }
        
    }
        return 0;
}