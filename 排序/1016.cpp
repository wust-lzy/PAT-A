#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    string name;
    int time, month, day, minute, hour, status;
};
bool cmp(node a,node b)
{
    if(a.name!=b.name)
        return a.name < b.name;
    else
    {
        return a.time < b.time;
    }
}
double f(int *rate,node n)
{
    double total = rate[n.hour] * n.minute + rate[24] * 60 * n.day;
    for (int i = 0; i < n.hour;i++)
        total += rate[i] * 60;
    return total / 100.0;
}
int main()
{
    int rate[25]={0}, n;
    for (int i = 0; i < 24;i++)
    {
        cin >> rate[i];
        rate[24] += rate[i];
    }
    cin >> n;
    vector<node> data(n);
    for (int i = 0; i < n;i++)
    {
        cin >> data[i].name;
        scanf("%d:%d:%d:%d",&data[i].month,&data[i].day,&data[i].hour,&data[i].minute);
        string temp;
        cin >> temp;
        data[i].status=(temp=="on-line")?1:0;
        data[i].time = data[i].day * 24 * 60 + data[i].hour * 60 + data[i].minute;
    }
    sort(data.begin(), data.end(), cmp);
    map<string, vector<node> > cus;
    for (int i = 0; i < n - 1;i++)
    {
        if(data[i].name==data[i+1].name&&data[i].status==1&&data[i+1].status==0)
        {
            cus[data[i].name].push_back(data[i]);
            cus[data[i+1].name].push_back(data[i+1]);
        }
    }
    for(auto it:cus)
    {
        double total = 0;
        vector<node> temp = it.second;
        cout << it.first << " ";
        printf("%02d\n",temp[0].month);
        for (unsigned int i = 0; i < temp.size();i+=2)
        {
            double t = f(rate, temp[i+1]) - f(rate, temp[i]);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", temp[i].day, temp[i].hour, temp[i].minute, temp[1+i].day, temp[1+i].hour, temp[1+i].minute, temp[i+1].time-temp[i].time,t);
            total += t;
        }
        printf("Total amount: $%.2lf\n", total);
    }
    return 0;
}