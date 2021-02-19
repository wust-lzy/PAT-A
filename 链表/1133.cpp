#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
遍历链表后将<0的结点先输出，再将0～k区间的结点输出，最后输出>k的结点
*/
struct node
{
    int ad, val, next,index;
};
int start, n, k;
vector<node> book(100005);
int main()
{
    cin >> start>> n>> k;
    int a,b,c;
    vector<node> ans;
    for (int i = 0; i < n;i++)
    {
        scanf("%d %d %d", &a,&b,&c);
        book[a] = {a, b, c,i};
    }
    for (int i = start; i != -1;i=book[i].next)
    {
        if(book[i].val<0)
            ans.push_back(book[i]);
    }
    for (int i = start; i != -1;i=book[i].next)
    {
        if(book[i].val>=0&&book[i].val<=k)
            ans.push_back(book[i]);
    }
    for (int i = start; i != -1;i=book[i].next)
    {
        if(book[i].val>k)
            ans.push_back(book[i]);
    }
    for (int i = 0; i < ans.size() - 1;i++)
        ans[i].next = ans[i + 1].ad;
    for (int i = 0; i < ans.size();i++)
    {
        if(i!=ans.size()-1)
            printf("%05d %d %05d\n", ans[i].ad, ans[i].val, ans[i].next);
        else
            printf("%05d %d -1", ans[i].ad, ans[i].val);
    }
    return 0;
}