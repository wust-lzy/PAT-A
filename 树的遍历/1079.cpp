#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
dfs树的遍历
理解题目好困难
题目给出根节点的单价，给出一棵树
如果k为0 则输入的是该节点的进货数量
否则输入的是该节点的孩子个数
dfs遍历 到叶子节点就加上进货量 最后乘上一个单价
*/
struct node
{
    double data;
    vector<int> child;
};
vector<node> book;
double ans=0.0, p, r;
void dfs(int key,int depth)
{
    if(book[key].child.size()==0) //到达叶子节点
    {
        ans += book[key].data * pow(r + 1, depth);
        return;
    }
    for (int i = 0; i < book[key].child.size(); i++)
    {
        dfs(book[key].child[i],depth + 1);
    }
}
int main()
{
    int n,k;
    cin >> n >> p >> r;
    r /= 100;
    book.resize(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        if (!k)
        {
            scanf("%lf", &book[i].data);
        }
        else
        {
            for (int j = 0; j<k; j++)
            {
                int temp;
                scanf("%d", &temp);
                book[i].child.push_back(temp);
            }
        }
    }
    dfs(0, 0);
    printf("%.1lf\n", ans*p);
    return 0;
}
