#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
模拟排序题  老坑点是排名问题，相同排名 名次一样
最大的坑点就是  已经是ok状态的 提交没过编译器的  算0分
不ok的  没过编译器  还是不管
*/
struct stu
{
    bool ok; //是否能进入排行榜
    int total, id, perfect,rank,p[10];
};
bool cmp(stu a, stu b)
{
    if (a.total != b.total)
    {
        return a.total > b.total;
    }
    else if (a.perfect != b.perfect)
    {
        return a.perfect > b.perfect;
    }
    else
    {
        return a.id < b.id;
    }
}
int main()
{
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    vector<stu> book(n + 1), ans;
    vector<int> mark(k + 1);
    for (int i = 1; i <= k; i++) //输入满分
    {
        scanf("%d", &mark[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        book[i].id = i;
        for (int j = 1; j <= k; j++) //初始化分数为-2
        {
            book[i].p[j] = -2;
        }
    }
    int id, problem_id, problem_mark;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &id, &problem_id, &problem_mark);
        if(problem_mark>=0)
            book[id].ok = 1;
        book[id].p[problem_id] = max(problem_mark, book[id].p[problem_id]); //多次提交，取最大值
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (book[i].ok==1)
            {
                if (book[i].p[j]==-1)
                {
                    book[i].p[j] = 0;
                }
                else if (book[i].p[j]>-1)
                {
                    book[i].total += book[i].p[j];
                }
            }          
            if (book[i].p[j] == mark[j])
            {
                book[i].perfect++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (book[i].ok)
        {
            ans.push_back(book[i]);
            //printf("%d %d\n", book[i].id, book[i].total);
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    ans[0].rank = 1;
    printf("%d %05d %d", 1, ans[0].id, ans[0].total);
    for (int j = 1; j <= k; j++)
    {
        if (ans[0].p[j] == -2)
        {
            printf(" -");
        }
        else
        {
            printf(" %d", ans[0].p[j]);
        }
    }
    printf("\n");
    for (int i = 1; i < ans.size(); i++)
    {
        ans[i].rank = ans[i].total == ans[i - 1].total ? ans[i - 1].rank : i + 1;
        printf("%d %05d %d", ans[i].rank, ans[i].id, ans[i].total);
        for (int j = 1; j <= k; j++)
        {
            if (ans[i].p[j] == -2)
            {
                printf(" -");
            }
            else
            {
                printf(" %d", ans[i].p[j]);
            }
        }
        printf("\n");
    }
    return 0;
}
