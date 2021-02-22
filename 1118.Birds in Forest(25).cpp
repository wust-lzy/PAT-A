#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
并查集  合并操作直接将第一个和后面的合并起来即可
用set统计元素的个数
题目说鸟的编号从1~n连续，因此统计集合个数的时候直接从1遍历到元素个数即可
*/
int father[10001];
int findfather(int x) //路径压缩写法
{
    if(x==father[x])
        return x;
    else
    {
        int f = findfather(father[x]);
        father[x] = f;
        return f;
    }
}
void Union(int a,int b)
{
    int fa = findfather(a);
    int fb = findfather(b);
    if (fa!=fb)
    {
        father[fa] = fb;
    }
}
void init()
{
    for (int i = 0; i < 10001; i++)
        father[i] = i;
}
int main()
{
    init();
    unordered_set<int> s;
    int n, k,a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d %d", &k,&a);
        s.insert(a);
        for (int j = 1; j < k;j++) // 全部合并
        {
            scanf("%d", &t);
            s.insert(t);
            Union(a, t);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= s.size();i++)//统计集合个数
    {
        if(findfather(i)==i)
            cnt++;
    }
    cout << cnt << " " << s.size() << endl;
    int q,ta,tb;
    cin >> q;
    for (int i = 0; i < q;i++)
    {
        scanf("%d %d", &ta, &tb);
        printf("%s\n", findfather(ta) == findfather(tb) ? "Yes" : "No");
    }
    return 0;
}