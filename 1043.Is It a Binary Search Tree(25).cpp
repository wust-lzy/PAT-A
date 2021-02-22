#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
二叉搜索树的建立，与插入结点
*/
struct node
{
    int data;  //数据域
    node *left, *right; //指针域
};
void ins(node * &root,int data) //排序二叉树建树
{
    if(root==NULL)
    {
        root = new node;
        root->data = data;
        root->left = root->right = NULL;
        return;
    }
    if(data<root->data)
        ins(root->left, data);
    else
    {
        ins(root->right, data);
    }
}
void preorder(node*root,vector<int>&vi) //先序建树
{
    if(root==NULL)
        return;
    vi.push_back(root->data);
    preorder(root->left, vi);
    preorder(root->right, vi);
}
void preorder_mirror(node*root,vector<int>&vi) //先序镜像建树
{
    if(root==NULL)
        return;
    vi.push_back(root->data);
    preorder_mirror(root->right, vi);
    preorder_mirror(root->left, vi);
}
void postorder(node*root,vector<int>&vi) //后序建树
{
    if(root==NULL)
        return;
    postorder(root->left, vi);
    postorder(root->right, vi);
    vi.push_back(root->data);
}
void postorder_mirror(node*root,vector<int>&vi) //后序镜像建树
{
    if(root==NULL)
        return;
    postorder_mirror(root->right, vi);
    postorder_mirror(root->left, vi);
    vi.push_back(root->data);
}
vector<int> origin, pre, prem, post, postm;
int main()
{
    int n, data;
    node *root = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n;i++)
    {
        scanf("%d", &data);
        origin.push_back(data);
        ins(root, data);
    }
    preorder(root, pre);//先序
    preorder_mirror(root, prem);//镜像先序
    postorder(root, post);//后序
    postorder_mirror(root, postm);//镜像后序
    if(origin==pre)//如果输入的序列是先序
    {
        printf("YES\n");
        for (int i = 0; i < post.size();i++)
        {
            printf("%d", post[i]);
            if(i!=post.size()-1)
                printf(" ");
        }
    }
    else if(origin==prem)//如果是镜像先序
    {
        printf("YES\n");
        for (int i = 0; i < postm.size();i++)
        {
            printf("%d", postm[i]);
            if(i!=postm.size()-1)
                printf(" ");
        }
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}