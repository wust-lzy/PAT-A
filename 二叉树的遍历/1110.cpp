#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
完全二叉树的判定
递归出最大的下标值，完全二叉树一定把前面的下标充满： 
最大的下标值 == 最大的节点数；
不完全二叉树前满一定有位置是空，会往后挤： 
最大的下标值 > 最大的节点数～
*/
int maxindex = -1,ans;
bool vis[100];
struct node
{
    int lchild, rchild;
};
node v[100];
void dfs(int root,int index)
{
    if (index>maxindex)
    {
        maxindex = index;
        ans = root;
    }
    if (v[root].lchild!=-1)
    {
        dfs(v[root].lchild, 2 * index);
    }
    if (v[root].rchild!=-1)
    {
        dfs(v[root].rchild, 2 * index+1);
    }
}
int main()
{
    int n,root=-1;
    string a, b;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if(isdigit(a[0]))
        {
            v[i].lchild = stoi(a);
            vis[stoi(a)] = 1;
        }
        else
            v[i].lchild = -1;
        if(isdigit(b[0]))
        {
            v[i].rchild = stoi(b);
            vis[stoi(b)] = 1;
        }
        else
            v[i].rchild = -1;
    }
    for (int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            root = i;
            break;
        }
    }
    dfs(root, 1);
    if (maxindex==n)
    {
        cout << "YES " << ans;
    }
    else
    {
        cout << "NO " << root;
    }
    return 0;
}