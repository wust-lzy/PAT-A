#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
链表的反转  一开始自己模拟 18分  不知道错误在哪里
后来 用了c++标准库reverse函数  简洁多了，而且不容易出错
坑点就是  每个断层处的next还要修改一遍
*/
struct node
{
    int address, data, next;
};
int main()
{
    vector<node> book(100001);
    int start, n, k;
    cin >> start >> n >> k;
    vector<node>ans;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        book[a] = {a, b, c};
    }
    int pos = start;
    while (1)
    {
        if (ans.size()%k==0&&ans.size()!=0)
        {
            reverse(ans.end() - k, ans.end());
        }
        if (pos==-1)
        {
            break;
        }
        ans.push_back(book[pos]);
        pos = book[pos].next;
    }
    for (int i = 0; i < ans.size()-1; i++)
    {
        ans[i].next = ans[i + 1].address;
        printf("%05d %d %05d\n", ans[i].address, ans[i].data, ans[i].next);
    }
    printf("%05d %d %d\n", ans[ans.size()-1].address, ans[ans.size()-1].data, -1);
    return 0;
}
/*
00100 6 3
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
*/