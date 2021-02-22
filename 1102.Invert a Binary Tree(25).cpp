#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
二叉树的反转  右孩子赋值给左孩子 、、
坑点是一开始数组开少了 题目说的10  开110才能过
100都不够
*/
struct node
{
    int data, lchild, rchild;
};
vector<node> v;
vector<int> level, in;
void level_traverse(int index)
{
    queue<int> q;
    q.push(index);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        level.push_back(v[temp].data);
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
void in_traverse(int index)
{
    if (v[index].lchild!=-1)
    {
        in_traverse(v[index].lchild);
    }
    in.push_back(v[index].data);
    if (v[index].rchild!=-1)
    {
        in_traverse(v[index].rchild);
    }
}
int main()
{
    int n;
    bool vis[100]={0};
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        string l, r;
        cin >> l >> r;
        v[i].data = i;
        if(l!="-")
        {
            v[i].rchild = stoi(l);
            vis[stoi(l)] = 1;
        }
        else
        {
            v[i].rchild = -1;
        }
        if(r!="-")
        {
            v[i].lchild = stoi(r);
            vis[stoi(r)] = 1;
        }
        else
        {
            v[i].lchild = -1;
        }
    }
    int root = -1;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            root = i;
            break;
        }
    }
    level_traverse(root);
    in_traverse(root);
    for (int i = 0; i < n; i++)
    {
        printf("%d", level[i]);
        if (i!=n-1)
        {
            printf(" ");
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        printf("%d", in[i]);
        if (i!=n-1)
        {
            printf(" ");
        }
    }
    return 0;
}