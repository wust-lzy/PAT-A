#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char C[4] = {'A', 'C', 'M', 'E'};
map<string, int> book;  //学生花名册
vector<double> cj[4];   //统计成绩表
map<double, int> pm[4]; //统计成绩排名
double a, b, c;
string id;
int n, m;
bool cmp(double a, double b)
{
    return a > b;
}
struct stu
{
    string id;
    pair<double, int> p[4]; //c,m,e的分数和排名
    int cnt;
    stu(double c, double m, double e)
    {
        cnt = 10000;
        p[0].first = (c + m + e) / 3;
        p[1].first = c;
        p[2].first = m;
        p[3].first = e;
    }
};
vector<stu> v; //学生表
void in()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> id >> a >> b >> c;
        book[id] = i + 1;
        double ave = (a + b + c) / 3;
        cj[0].push_back(ave);      //平均成绩
        cj[1].push_back(a);        //c语言
        cj[2].push_back(b);        //math
        cj[3].push_back(c);        //English
        v.push_back(stu(a, b, c)); //插入学生信息
    }
}
void work()
{
    for (int i = 0; i < 4; i++)
        sort(cj[i].begin(), cj[i].end(), cmp);
    for (int i = 0; i < 4; i++) //每门成绩弄个排名表
    {
        int cnt = 0;
        double t = cj[i][0];
        pm[i][t] = ++cnt;
        for (unsigned int j = 1; j < cj[i].size(); j++)
        {
            if(cj[i][j]==cj[i][j-1])
            {
                double tt=cj[i][j];
                pm[i][tt] = cnt;
            }
            else
            {
                double tt=cj[i][j];
                pm[i][tt] = j+1;
                cnt++;
            }
            
            
        }
    }
    for (unsigned i = 0; i < v.size(); i++) //给每个学生每门成绩填上排名
    {
        for (int j = 0; j < 4; j++)
        {
            v[i].p[j].second = pm[j][v[i].p[j].first];
            if (v[i].cnt > pm[j][v[i].p[j].first])
                v[i].cnt = pm[j][v[i].p[j].first];
        }
    }
}
void out(stu s)
{
    for (int i = 0; i < 4; i++)
    {
        if(s.p[i].second==s.cnt)
        {
            cout << s.cnt << " " << C[i];
            break;
        }
        //cout << "(" << s.p[i].second << ")" << s.p[i].first << " ";
    }
    cout << endl;
}
int main()
{
    in();
    work();                     //排序
    for (int i = 0; i < m; i++) //输出
    {
        cin >> id;
        if (book[id])
        {
            out(v[book[id] - 1]);
        }
        else
        {
            cout << "N/A" << endl;
        }
    }
    return 0;
}