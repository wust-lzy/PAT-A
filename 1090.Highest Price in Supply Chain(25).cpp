#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
dfs树的遍历
这句话不理解
each number Si
​​is the index of the supplier for the i-th member. S​root
​​for the root supplier is defined to be −1. 
*/
int n,ans_sum=0,maxdepth=-1;
double p, r;
vector<int> ans[100001];
void dfs(int root,int depth)
{
    if (ans[root].empty())
    {
        if (depth==maxdepth)
        {
            ans_sum++;
        }
        if (depth>maxdepth)
        {
            maxdepth = depth;
            ans_sum = 1;
        }
        return;
    }
    for (int i = 0; i < ans[root].size(); i++)
    {
        dfs(ans[root][i], depth + 1);
    }
}
int main()
{
    cin >> n >> p >> r;
    r /= 100;
    int root;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (temp==-1)
        {
            root = i;
        }
        else
        {
            ans[temp].push_back(i);
        }
    }
    dfs(root, 0);
    printf("%.2lf %d", p * pow(1 + r, maxdepth), ans_sum);
    return 0;
}