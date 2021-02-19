#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
二叉查找树的建树、层序遍历
*/
struct node
{
    int data;
    int lchild, rchild;
};
vector<node> v;
vector<int> in, ans;
int cnt = 0;
void build_tree(int index)
{
    if (v[index].lchild != -1) //左
    {
        build_tree(v[index].lchild);
    }
    v[index].data = in[cnt++]; //根
    if (v[index].rchild != -1) //右
    {
        build_tree(v[index].rchild);
    }
}
void level_traverse(int index)
{
    queue<int> q;
    q.push(index);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        ans.push_back(v[temp].data);
        if (v[temp].lchild != -1) //左
        {
            q.push(v[temp].lchild);
        }
        if (v[temp].rchild != -1) //右
        {
            q.push(v[temp].rchild);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    v.resize(n);
    in.resize(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &v[i].lchild, &v[i].rchild);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }
    sort(in.begin(), in.end());
    build_tree(0);
    level_traverse(0);
    for (int i = 0; i < n; i++)
    {
        printf("%d", ans[i]);
        if (i!=n-1)
        {
            printf(" ");
        }
    }  
    return 0;
}
