#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
已知后序和中序
输出层序遍历的结果~
*/
int post[35], in[35];
map<int, int> ans;
/*
i表示后序中根节点在中序中的位置
左子树的根在后序中为root-(end-i+1) 当前根-（右子树的个数+1）
左子树的起点为start，末尾为i-1
右子树的根为root-1，起点为i+1，末尾为end
*/
void level(int root,int start,int end,int index)
{
    if(start>end)
        return;
    int i = start;
    while(i<end&&in[i]!=post[root])
        i++;
    ans[index] = post[root];
    level(root - (end - i + 1), start, i - 1, 2 * index);//左子树
    level(root - 1, i + 1, end, 2 * index + 1); //右子树
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n;i++)
        cin >> post[i];
    for (int i = 0; i < n;i++)
        cin >> in[i];
    level(n - 1, 0, n - 1, 1);
    auto it = ans.begin();
    cout << it->second;
    while(++it!=ans.end())
        cout << " " << it->second;
    return 0;
}