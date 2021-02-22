#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
已知二叉树的前序和中序 输出后序
*/
int pre[35], in[35],ans[35],cnt=0;
void post(int root,int start,int end)
{
    if (start>end)
    {
        return;
    }
    int i = start;
    while (i<end&&in[i]!=pre[root])
    {
        i++;
    }
    post(root + 1, start, i - 1);
    post(root + 1 + i - start, i + 1, end);
    ans[cnt++] = pre[root];
}
int main()
{
    int n, cnt1 = 0, cnt2 = 0;
    string temp;
    stack<int> s;
    cin >> n;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> temp;
        if (temp == "Push")
        {
            cin >> pre[cnt1++];
            s.push(pre[cnt1 - 1]);
        }
        else if (temp == "Pop")
        {
            in[cnt2++] = s.top();
            s.pop(); 
        }
    }
    post(0, 0, n-1);
    for (int i = 0; i < cnt; i++)
    {
        cout << ans[i];
        if (i!=cnt-1)
        {
            cout << " ";
        }
    }
    return 0;
}