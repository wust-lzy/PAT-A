#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
排序问题，总人数有很多，但是每次显示不超过100个，所以只将部分人存入到查询的数组中
因为输入输出很多，所以不能用string  全部用scanf和printf
*/
struct person
{
    char name[10];
    int age, worth;
};
bool cmp(person a ,person b)
{
    if(a.worth!=b.worth)
        return a.worth > b.worth;
    else if(a.age!=b.age)
        return a.age < b.age;
    else
    {
        return strcmp(a.name,b.name)<0;
    }
}
int main()
{
    int n,k;
    cin >> n >> k;
    vector<person> all(n), v;
    vector<int> age(201);//统计每个年龄的人数
    for (int i = 0; i < n;i++)
    {
        scanf("%s %d %d", all[i].name,&all[i].age, &all[i].worth);
    }
    sort(all.begin(), all.end(), cmp);
    for (int i = 0; i < n;i++)
    {
        if(age[all[i].age]<100) //每个年龄只存入100个人
        {
            v.push_back(all[i]);
            age[all[i].age]++;
        }
    }
    for (int i = 0; i < k;i++)
    {
        int m, amin, amax;
        vector<person> t;
        scanf("%d%d%d", &m, &amin, &amax);
        printf("Case #%d:\n", i + 1);
        for (int j = 0; j < v.size();j++)
        {
            if(v[j].age>=amin&&v[j].age<=amax)
                t.push_back(v[j]);
        }
        if(t.size()>0)
        {
            for (int j = 0; j < t.size()&&j<m;j++)
            {
                printf("%s %d %d\n", t[j].name,t[j].age, t[j].worth);
            }
        }
        else
        {
            printf("None\n");
        }
        
    }
    return 0;
}