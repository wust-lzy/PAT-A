#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
已知二叉树的前序和中序 输出后序
*/
int pre[50005], in[50005],ans[50005],flag=1;
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
    if(flag)
    {
        flag = 0;
        printf("%d", pre[root]);
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n;i++)
        scanf("%d", &pre[i]);
    for (int i = 0; i < n;i++)
        scanf("%d", &in[i]);
    post(0, 0, n - 1);
    return 0;
}