#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    int val;
    node *left, *right;
};
void ins(node *&root,int v)
{
    if(root==NULL)
    {
        root = new node();
        root->val = v;
        root->left = root->right = NULL;
    }
    else if(abs(v)<abs(root->val))
        ins(root->left, v);
    else
        ins(root->right, v);
}
bool fun1(node *root)//判断父节点是红色，子节点是不是黑色
{
    if(root==NULL)
        return 1;
    if(root->val<0)
    {
        if(root->left!=NULL&&root->left->val<0)
            return 0;
        if(root->right!=NULL&&root->right->val<0)
            return 0;
    }
    return fun1(root->left) && fun1(root->right);
}
int getnum(node *root)//获取每条路的黑结点数
{
    if(root==NULL)
        return 0;
    int l = getnum(root->left);
    int r = getnum(root->right);
    return root->val > 0 ? max(l, r) + 1 : max(l, r);
}
bool fun2(node *root)//判断每条路上黑结点数是否相同
{
    if(root==NULL)
        return 1;
    int l = getnum(root->left);
    int r = getnum(root->right);
    if(l!=r)
        return 0;
    return fun2(root->left) && fun2(root->right);
}
int main()
{
    int k, n;
    cin >> k;
    while(k--)
    {
        cin >> n;
        vector<int> v(n);
        node *root = NULL;
        for (int i = 0; i < n;i++)
        {
            cin >> v[i];
            ins(root, v[i]);
        }
        if(v[0]<0||!fun1(root)||!fun2(root))
            cout << "No\n";
        else
            cout << "Yes\n";
        cout << "black nodes:" << getnum(root) << endl;
    }
    return 0;
}
