#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node
{
    string id, name;
    int score;
};
bool cmp1(node a,node b)
{
    return a.id < b.id;
}
bool cmp2(node a,node b)
{
    if(a.name!=b.name)
        return a.name <= b.name;
    else
    return a.id < b.id;
}
bool cmp3(node a,node b)
{
    if(a.score!=b.score)
        return a.score <= b.score;
    else
    return a.id < b.id;
}
int main()
{
    int n, col;
    cin >> n >> col;
    vector<node> stu(n);
    for (int i = 0; i < n;i++)
        cin >> stu[i].id >> stu[i].name >> stu[i].score;
    if(col==1)
        sort(stu.begin(), stu.end(), cmp1);
    else if(col==2)
        sort(stu.begin(), stu.end(), cmp2);
    else
    {
        sort(stu.begin(), stu.end(), cmp3);
    }
    for (int i = 0; i < n;i++)
        cout << stu[i].id << " " << stu[i].name << " " << stu[i].score << endl;
    return 0;
}