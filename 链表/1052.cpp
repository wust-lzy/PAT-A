#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
链表的遍历,题目有个坑点就是。。  有些结点不在链表中
因为这个原因自己的代码只有21分   
struct node
{
    int ad, key, next;
};
bool cmp(node a,node b)
{
    return a.key < b.key;
}
int main()
{
    int n, head;
    scanf("%d %d", &n, &head);
    vector<node> v(n);
    for (int i = 0; i < n;i++)
    {
        scanf("%d %d %d", &v[i].ad, &v[i].key, &v[i].next);
    }
    sort(v.begin(), v.end(), cmp);
    printf("%d %05d\n", v.size(), v[0].ad);
    for (int i = 0; i < n - 1;i++)
    {
        printf("%05d %d %05d\n", v[i].ad, v[i].key, v[i + 1].ad);
    }
    printf("%05d %d -1\n", v[n-1].ad, v[n-1].key);
    return 0;
}*/
struct node
{
    int ad, key, next;
    bool flag;
}book[100000];

bool cmp(node a, node b) //将不在链表中的结点放在后面
{
    if(a.flag&&b.flag)
        return a.key < b.key;
    else
    {
        return a.flag > b.flag;
    }
}
int main()
{
    int n, head,cnt=0;
    scanf("%d%d", &n, &head);
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        book[a] = {a, b, c, false};
    }
    for (int i = head; i != -1; i = book[i].next) //遍历链表 将链表中的结点标记为1
    {
        book[i].flag = 1;
        cnt++;
    }
    if(!cnt)
        printf("0 -1");
    else
    {
        sort(book, book + 100000, cmp);
        printf("%d %05d\n", cnt, book[0].ad);
        for (int i = 0; i < cnt; i++)
        {
            if(i!=cnt-1)
            {
                printf("%05d %d %05d\n", book[i].ad, book[i].key, book[i + 1].ad);
            }
            else
            {
                printf("%05d %d -1\n", book[i].ad, book[i].key);
            }
        }
        return 0;
    }
}