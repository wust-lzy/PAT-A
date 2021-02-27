#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
大顶堆和小顶堆的判定
二叉树的后序输出
*/
struct node
{
    int data, left = -1, right = -1;
};
bool fun1(vector<node> &v, int n)
{
    for (int i = 1; i <= n; i++)
    {
        int temp = v[i].data;
        if (v[i].left != -1)
        {
            if (temp < v[v[i].left].data)
                return 0;
        }
        if (v[i].right != -1)
        {
            if (temp < v[v[i].right].data)
                return 0;
        }
    }
    return 1;
}
bool fun2(vector<node> &v, int n)
{
    for (int i = 1; i <= n; i++)
    {
        int temp = v[i].data;
        if (v[i].left != -1)
        {
            if (temp > v[v[i].left].data)
                return 0;
        }
        if (v[i].right != -1)
        {
            if (temp > v[v[i].right].data)
                return 0;
        }
    }
    return 1;
}
vector<int> ans;
void postorder(vector<node> &v, int root)
{
    if (v[root].left != -1)
        postorder(v, v[root].left);
    if (v[root].right != -1)
        postorder(v, v[root].right);
    ans.push_back(v[root].data);
}
int main()
{
    int t, n;
    cin >> t >> n;
    while (t--)
    {
        int t;
        vector<node> v(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> t;
            v[i].data = t;
            if (2 * i <= n)
                v[i].left = 2 * i;
            if (2 * i + 1 <= n)
                v[i].right = 2 * i + 1;
        }
        ans.clear();
        postorder(v, 1);
        if (fun1(v, n))
            printf("%s\n", "Max Heap");
        else if (fun2(v, n))
            printf("%s\n", "Min Heap");
        else
            printf("Not Heap\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d", ans[i]);
            if (i != n - 1)
                printf(" ");
            else
                printf("\n");
        }
    }
    return 0;
}
