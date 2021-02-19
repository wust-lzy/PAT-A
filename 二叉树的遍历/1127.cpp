#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
二叉树 已知后序和中序转为层序
建树之后  按z字型输出
*/
int post[35], in[35];
int max_level = -1;
struct node
{
    int data, depth;
    node *left, *right;
};
vector<int> ans[1000];
void level(int root, int start, int end, int depth, node *&ans)
{
    if (start > end)
        return;
    int i = start;
    while (i < end && in[i] != post[root])
        i++;
    if (ans == NULL)
    {
        ans = new node;
        ans->depth = depth;
        ans->left = ans->right = NULL;
        ans->data = post[root];
    }
    level(root - (end - i + 1), start, i - 1, depth + 1, ans->left);
    level(root - 1, i + 1, end, depth + 1, ans->right);
}
void func(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        ans[temp->depth].push_back(temp->data);
        max_level = max(max_level, temp->depth);
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> in[i];
    for (int i = 0; i < n; i++)
        cin >> post[i];
    node *root = NULL;
    level(n - 1, 0, n - 1, 1, root);
    func(root);
    int fir = 1;
    for (int i = 1; i <= max_level; i++)
    {
        if (i & 1)
        {
            for (int j = ans[i].size() - 1; j >= 0;j--)
            {
                if(fir)
                {
                    fir = 0;
                    cout << ans[i][j];
                }
                else
                {
                    cout << " " << ans[i][j];
                }
                
            }
        }
        else
        {
            for (int j = 0; j < ans[i].size();j++)
            {
                if(fir)
                {
                    fir = 0;
                    cout << ans[i][j];
                }
                else
                {
                    cout << " " << ans[i][j];
                }
            }
        }
    }
    return 0;
}