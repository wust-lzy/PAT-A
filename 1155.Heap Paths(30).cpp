#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
大顶堆和小顶堆的判定
dfs从右子树到左子树遍历
*/
int n;
vector<int> ans;
vector<int> v;
void dfs(int index)
{
    if(index*2>n)//判断当前结点是否为叶子结点
    {
        if(index<=n)
        {
            for (int i = 0; i < ans.size();i++)
            {
                cout << ans[i];
                if(i!=ans.size()-1)
                    cout << " ";
                else
                    cout << "\n";
            }
        }
    }
    else
    {
        ans.push_back(v[2 * index+1]);
        dfs(2 * index+1);
        ans.pop_back();

        ans.push_back(v[2 * index]);
        dfs(2 * index);
        ans.pop_back();
    }
}
int main()
{
    cin  >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n;i++)
        scanf("%d", &v[i]);
    ans.push_back(v[1]);
    dfs(1);
    bool flag1 = 1, flag2 = 2;
    for (int i = 2; i <= n;i++)
    {
        if(v[i]<v[i/2])//子节点小于父节点
            flag2 = 0;
        if(v[i]>v[i/2])
            flag1 = 0;
    }
    if(flag1)
        cout << "Max Heap\n";
    else if(flag2)
        cout << "Min Heap\n";
    else
        cout << "Not Heap\n";
    return 0;
}
