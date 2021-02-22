#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
链表的遍历  删除重复的结点
*/
struct node
{
    int ad, key, next;
};
node book[100005];
bool m[100005];
int main()
{
    int start, n;
    vector<node> ans,rest;
    cin >> start >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        scanf("%05d %d %05d", &a, &b, &c);
        book[a] = {a, b, c};
    }
    for (int i = start; i !=-1; i=book[i].next)
    {
        node temp = {book[i].ad, book[i].key, book[i].next};
        if (!m[abs(book[i].key)])
        {
            m[abs(book[i].key)] = 1;
            ans.push_back(temp);
        }
        else
        {
            rest.push_back(temp);
        }
        
    }
    // cout << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        if (i!=ans.size()-1)
        {
            printf("%05d %d %05d\n", ans[i].ad, ans[i].key, ans[i+1].ad);
        }
        else
        {
            printf("%05d %d -1\n", ans[i].ad, ans[i].key);
        } 
    }
    
    // cout << endl;
    for (int i = 0; i < rest.size(); i++)
    {
        if (i!=rest.size()-1)
        {
            printf("%05d %d %05d\n", rest[i].ad, rest[i].key, rest[i+1].ad);
        }
        else
            printf("%05d %d -1\n", rest[i].ad, rest[i].key);
    }
    return 0;
}