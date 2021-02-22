#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
学生选课，输入学生姓名，求学生选的课程
哈系表，每个学生对应一个课程集合，并对课程进行排序
*/
map<string, vector<int> >book;//给学生编号
int main()
{
    int n, k, num = 0;
    cin >> n >> k;
    string query[n];
    for (int i = 0; i < k;i++)
    {
        int index, cnt;
        scanf("%d %d", &index, &cnt);
        for (int t = 0; t < cnt;t++)
        {
            string s;
            cin >> s;
            book[s].push_back(index); //添加一门课
        }
    }
    for (int i = 0; i < n;i++)
        cin >> query[i];
    for (int i = 0; i < n;i++)
    {
        cout << query[i] << " " << book[query[i]].size();
        sort(book[query[i]].begin(), book[query[i]].end());
        for (int j = 0; j < book[query[i]].size();j++)
            cout << " " << book[query[i]][j];
        printf("\n");
    }
        return 0;
}