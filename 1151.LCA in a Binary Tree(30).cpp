#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<int, int> pos;
vector<int> in, pre;
void lca(int inl,int inr,int preroot,int a,int b)
{
    if(inl>inr)
        return;
    int inroot=pos[pre[preroot]],ain=pos[a],bin=pos[b];
    if(ain<inroot&&bin<inroot)
        lca(inl, inroot - 1, preroot + 1, a, b);
    else if(ain<inroot&&bin>inroot||ain>inroot&&bin<inroot)
        printf("LCA of %d and %d is %d.\n", a, b, in[inroot]);
    else if(ain>inroot&&bin>inroot)
        lca(inroot + 1, inr, preroot + 1 + (inroot - inl), a, b);
    else if(ain==inroot)
        printf("%d is an ancestor of %d.\n", a, b);
    else if(bin==inroot)
        printf("%d is an ancestor of %d.\n", b, a);
}
int main()
{
    int m, n, a, b;
    cin >> m >> n;
    in.resize(n + 1);
    pre.resize(n + 1);
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &in[i]);
        pos[in[i]] = i;
    }
    for (int i = 1; i <= n;i++)
        cin >> pre[i];
    for (int i = 0;i<m; i++)
    {
        scanf("%d %d", &a, &b);
        if(pos[a]==0&&pos[b]==0)
            printf("ERROR: %d and %d are not found.\n", a, b);
        else if(pos[a]==0||pos[b]==0)
            printf("ERROR: %d is not found.\n", a == 0 ? a : b);
        else
            lca(1, n, 1, a, b);
    }
        return 0;
}