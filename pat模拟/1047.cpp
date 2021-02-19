#include <bits/stdc++.h>
using namespace std;
/*
学生选课，输入课程号，求选这门课的学生
不能用map，会超时。每门课对应一个学生集合，并对学生名字进行排序
*/
vector<string> book[50001];//每门课程的学生名单
int main()
{
    int n, k;
    scanf("%d %d", &n,&k);
    for (int i = 0; i < n;i++)
    {
        string name;
        int cnt, index;
        cin >> name;
        scanf("%d",&cnt);
        for (int t = 0; t < cnt;t++)
        {
            scanf("%d", &index);
            book[index].push_back(name); //课程添加学生
        }
    }
    for (int i = 1; i <= k;i++)
    {
        printf("%d %d\n", i, book[i].size());
        sort(book[i].begin(), book[i].end());
        for (auto it = book[i].begin(); it != book[i].end();it++)
            printf("%s\n", (*it).c_str());
    }
    return 0;
}