#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct wd  //窗口
{
    int a;//当前队首出队时间
    int endtime;//当前队尾结束时间
    queue<int> c; //窗口每个人的处理时间
};
int main()
{
    wd w[1005]; //窗口
    int time[1005],ans[1005];//每个人的处理时间，每个人的答案
    bool sorry[1005];
    int n, m, k, q, index = 1;
    cin >> n >> m >> k >> q;
    for (int i = 1; i <= k; i++)
        cin >> time[i];
    for (int i = 1; i <= m;i++) //每个窗口排m个
    {
        for (int j = 1; j <= n;j++) //有n个窗口
        {
            if(index<=k)
            {
                w[j].c.push(time[index]);
                if(w[j].endtime >= 540)
                sorry[index] = 1;
                w[j].endtime += time[index];
                if(i==1)//在第一排  初始化队首时间
                {
                    w[j].a = time[index];
                }
                ans[index++] = w[j].endtime;
            }
        }
    }
    while(index<=k)
    {
        int tmin = w[1].a;
        int twd = 1;
        for (int i = 2; i <= n;i++)
        {
            if(w[i].a<tmin)
            {
                tmin = w[i].a;
                twd = i;
            }
        }
        w[tmin].c.pop();
        w[tmin].c.push(time[index]);
        w[twd].a += w[twd].c.front();
        if(w[twd].endtime>=540)
            sorry[index] = 1;
        w[twd].endtime += time[index];
        ans[index] = w[twd].endtime;
        index++;
    }
    for (int i = 1; i <= q;i++)
    {
        int t;
        cin >> t;
        if(sorry[t])
            cout << "Sorry" << endl;
        else
        {
            printf("%02d:%02d\n", (ans[t]+480) / 60, ans[t] % 60);
        }
    }
    return 0;
}