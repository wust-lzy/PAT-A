#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
二叉查找树的建立  遍历
坑点是 小于等于结点值应该插在左子树
和平时的不一样
*/
int num[10000], max_level = -1;
struct node
{
    int data;
    node *lchild, *rchild;
};
void ins(node* &root, int data)
{
    if (root == NULL)
    {
        root = new node;
        root->data = data;
        root->lchild = root->rchild = NULL;
    }
    else if (data <= root->data)
    {
        ins(root->lchild, data);
    }
    else
        ins(root->rchild, data);
}
node *create(vector<int> data,int n)
{
    node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        ins(root, data[i]);
    }
    return root;
}
void dfs(node* root, int depth)
{
    if (root == NULL)
    {
        max_level = max(max_level, depth);
        return;
    }
    num[depth]++;
    dfs(root->lchild, depth + 1);
    dfs(root->rchild, depth + 1);
}
int main()
{
    int n, t;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    node *root = create(v, n);
    dfs(root, 0);
    printf("%d + %d = %d\n", num[max_level - 1], num[max_level - 2], num[max_level - 1] + num[max_level - 2]);
    return 0;
}