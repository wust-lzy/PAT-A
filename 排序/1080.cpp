#include<bits/stdc++.h>
using namespace std;
/*
模拟排序题
难点在于学校也要设立结构体，重要的变量是stuID 记录录取的学生
lastrank  记录最后录取学生的排名
*/
struct stu
{
    int ge, gi, total,rank,id;
    int choice[10];
};
struct school
{
    int num, lastrank;
    vector<int> stuID;
};

bool cmp(stu a,stu b)
{
    if (a.total!=b.total)
    {
        return a.total > b.total;
    }
    else
    {
        return a.ge > b.ge;
    }
}
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<school> s(m);
    vector<stu> v(n);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &s[i].num);
    }
    for (int i = 0; i < n; i++)
    {
        v[i].id = i;
        scanf("%d %d", &v[i].ge, &v[i].gi);
        v[i].total = v[i].ge + v[i].gi;
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &v[i].choice[j]);
        }
    }
    sort(v.begin(), v.end(), cmp);
    v[0].rank = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i].total==v[i-1].total&&v[i].ge==v[i-1].ge)
        {
            v[i].rank = v[i - 1].rank;
        }
        else
        {
            v[i].rank = i + 1;
        }
    }
    for (int i = 0; i < n; i++)//n个学生
    {
        for (int j = 0; j<k; j++)
        {
            int index = v[i].choice[j];
            if (s[index].lastrank==v[i].rank||s[index].num>0)
            {
                s[index].stuID.push_back(v[i].id);
                s[index].lastrank = v[i].rank;
                s[index].num--;
                break;//学生被录用 退出当前学校
            }       
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (!s[i].stuID.empty())
        {
            sort(s[i].stuID.begin(), s[i].stuID.end());
            for (int j = 0; j<s[i].stuID.size(); j++)
            {
                printf("%d", s[i].stuID[j]);
                if (j!=s[i].stuID.size()-1)
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
