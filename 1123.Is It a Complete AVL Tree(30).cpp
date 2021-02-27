#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
平衡二叉树模板+二叉树的层序遍历+完全二叉树的遍历
*/
struct node
{
    int v, height;
    node *left, *right;
};
node *newnode(int v)
{
    node *temp = new node;
    temp->v = v;
    temp->left = temp->right = NULL;
    temp->height = 1;
    return temp;
}
int getheight(node *root)
{
    if(root==NULL)
        return 0;
    return root->height;
}
int getBalanceFactor(node *root)
{
    return getheight(root->left) - getheight(root->right);
}
void updateheight(node *root)
{
    root->height = max(getheight(root->left), getheight(root->right))+1;
}
void L(node *&root)
{
    node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateheight(root);
    updateheight(temp);
    root = temp;
}
void R(node *&root)
{
    node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateheight(root);
    updateheight(temp);
    root = temp;
}
void ins(node *&root,int v)
{
    if(root==NULL)
    {
        root = newnode(v);
        return;
    }
    if(v<root->v)
    {
        ins(root->left, v);
        updateheight(root);
        if(getBalanceFactor(root)==2)
        {
            if(getBalanceFactor(root->left)==1)
                R(root);
            else if(getBalanceFactor(root->left)==-1)
            {
                L(root->left);
                R(root);
            }
        }
    }
    else
    {
        ins(root->right, v);
        updateheight(root);
        if(getBalanceFactor(root)==-2)
        {
            if(getBalanceFactor(root->right)==-1)
                L(root);
            else if(getBalanceFactor(root->right)==1)
            {
                R(root->right);
                L(root);
            }
        }
    }
}
node *buildTree(vector<int>&v)
{
    int len = v.size();
    node *root = NULL;
    for (int i = 0; i < len;i++)
        ins(root, v[i]);
    return root;
}
int max_index = -1,n;
vector<int>ans;
void bfs(node *root)
{
    queue<pair<node*,int> > q;
    q.push(pair<node*,int>(root,1));
    while(!q.empty())
    {
        pair<node *, int> temp = q.front();
        q.pop();
        max_index = max(max_index, temp.second);
        ans.push_back(temp.first->v);
        if(temp.first->left!=NULL)
            q.push(pair<node *, int>(temp.first->left, 2 * temp.second));
        if(temp.first->right!=NULL)
            q.push(pair<node *, int>(temp.first->right, 2*temp.second + 1))；
    }
}
int main()
{
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n;i++)
        scanf("%d", &v[i]);
    node *root = buildTree(v);
    bfs(root);
    for (int i = 0; i < ans.size();i++)
    {
        printf("%d", ans[i]);
        if(i!=ans.size()-1)
            printf(" ");
        else
            printf("\n");
    }
    // cout << max_index << " " << n << endl;
    printf("%s\n", max_index == n ? "YES" : "NO");
    return 0;
}
