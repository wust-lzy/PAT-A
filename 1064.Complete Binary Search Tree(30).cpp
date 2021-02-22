#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
考点  树的层序遍历
由二叉搜索树的性质，将序列排序可得到中序遍历结果
由中序遍历结果，将数填到层序遍历数组当中
*/
int in[1001],n,lev[1010],cnt=0;
void level(int root)
{
    if (root >= n)
        return;
    level(2 * root + 1);   //左
    lev[root] = in[cnt++];  //中
    level(2 * root + 2); //右
}
int main()
{
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        cin >> in[i];
    }
    sort(in, in + n);
    level(0);
    printf("%d", lev[0]);
    for (int i = 1; i < n;i++)
        printf(" %d", lev[i]);
    return 0;
}