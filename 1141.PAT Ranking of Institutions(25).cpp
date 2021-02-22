#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
map字符串 给学校排序
然后结构体排序
*/
struct school
{
    string name;
    int score[3]={0},total=0,ns=0,rank;
    school(int index,string name,int sc)
    {
        this->name = name;
        score[index] = sc;
        ns++;
    }
};
bool cmp(school a,school b)
{
    if(a.total!=b.total)
        return a.total > b.total;
    else if(a.ns!=b.ns)
        return a.ns < b.ns;
    else
        return a.name < b.name;
}
int main()
{
    unordered_map<char, int> m;
    m['B'] = 0;
    m['A'] = 1;
    m['T'] = 2;
    int n,score,cnt=0;
    unordered_map<string, int> vis;
    string stu, sch;
    cin >> n;
    vector<school> ans;
    for (int i = 0; i < n;i++)
    {
        cin >> stu >> score >> sch;
        transform(sch.begin(), sch.end(), sch.begin(), ::tolower);
        if(!vis[sch])
        {
            cnt++;
            ans.push_back(school(m[stu[0]], sch, score));
            vis[sch] = cnt;
        }
        else
        {
            int index =vis[sch]-1;
            ans[index].score[m[stu[0]]] += score;
            ans[index].ns++;
        }
    }
    for (int i = 0; i < ans.size();i++)
        ans[i].total = ans[i].score[0] / 1.5 + ans[i].score[1] + ans[i].score[2] * 1.5;
    sort(ans.begin(), ans.end(), cmp);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size();i++)
    {
        if(i==0)
            ans[i].rank = 1;
        else
        {
            if(ans[i].total==ans[i-1].total)
                ans[i].rank = ans[i - 1].rank;
            else
                ans[i].rank = i + 1;
        }
    }
    for (int i = 0; i < ans.size();i++)
    {
        // printf("%s %d %d %d %d\n", ans[i].name.c_str(), ans[i].score[0], ans[i].score[1], ans[i].score[2], ans[i].ns);
        printf("%d %s %d %d\n",ans[i].rank,ans[i].name.c_str(), ans[i].total, ans[i].ns);
    }
    return 0;
}
/*
1 cmu 192 2
1 au 192 3
3 pku 100 1
4 hypu 81 2
4 lanx 81 2
5
1 cmu 192 2
1 au 192 3
3 pku 100 1
4 hypu 81 2
4 lanx 81 2
*/