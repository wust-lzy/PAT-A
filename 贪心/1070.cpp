#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
简单结构体模拟题  根据性价比排序 卖月饼
*/
struct cake
{
    double weight,  price, cost_performance;
};
bool cmp(cake a,cake b)
{
    return a.cost_performance > b.cost_performance;
}
int main()
{
    int n, d;
    cin >> n >> d;
    vector<cake> v(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &v[i].weight);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &v[i].price);
        v[i].cost_performance = (double)v[i].price / v[i].weight ;
    }
    sort(v.begin(), v.end(),cmp);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << v[i].weight << " " << v[i].price << " " << v[i].cost_performance << endl;
    // }
    double total = 0;
    for (int i = 0; i < n; i++)
    {
        if(d==0)
            break;
        if(v[i].weight<=d)
        {
            total += v[i].price;
            d -= v[i].weight;
        }
        else
        {
            total += d * v[i].cost_performance;
            d = 0;
        }
    }
    printf("%.2lf\n", total);
    return 0;
}
