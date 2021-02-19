#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
平衡二叉树模板题
*/
struct node
{
    int v, height; // v为结点的权值 height为当前子树的高度
    node *lchild, *rchild; //左右孩子结点地址
};
node *newnode(int v) //生成一个新结点 v为结点的值
{
    node *Node = new node;
    Node->v = v;     
    Node->lchild = Node->rchild = NULL;
    Node->height = 1;
    return Node;
}
int getheight(node *root) 
{
    if (root == NULL)   //空节点的高度为0
        return 0;
    return root->height;
}
int getBalanceFactor(node *root) //计算平衡因子
{
    return getheight(root->lchild) - getheight(root->rchild);
}
void updateHeight(node *root)
{
    root->height = max(getheight(root->lchild), getheight(root->rchild)) + 1;
}
void search(node *root, int x)  //函数查找AVL树中数据域为x的结点
{
    if (root == NULL)
        printf("search failed\n");
    return;
    if (x == root->v)
        printf("%d\n", root->v);
    else if (x < root->v)
    {
        search(root->lchild, x);
    }
    else
    {
        search(root->rchild, x);
    }
}
void L(node * &root) //左旋
{
    node *temp = root->rchild;  //root指向结点A，temp指向结点B
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}
void R(node * &root)
{
    node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}
void insert(node * &root, int v)
{
    if (root == NULL)
    {
        root = newnode(v);
        return;
    }
    if (v < root->v)
    {
        insert(root->lchild, v);
        updateHeight(root);
        if (getBalanceFactor(root) == 2)
        {
            if (getBalanceFactor(root->lchild) == 1) //LL型
            {
                R(root);
            }
            else if (getBalanceFactor(root->lchild) == -1) //LR型
            {
                L(root->lchild);
                R(root);
            }
        }
    }
    else //v比根节点的权值大
    {
        insert(root->rchild, v);
        updateHeight(root);
        if (getBalanceFactor(root) == -2)
        {
            if (getBalanceFactor(root->rchild) == -1) //RR型
            {
                L(root);
            }
            else if (getBalanceFactor(root->rchild) == 1) //RL型
            {
                R(root->rchild);
                L(root);
            }
        }
    }
}
int main()
{
    node *root = NULL;
    int n, temp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        insert(root, temp);
    }
    cout << root->v;
    return 0;
}