#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
简单模拟，多项式的加法
*/
double a[1001];
int main()
{
    int k, b,cnt=0;
    double aa;
    cin >> k;
    for (int i = 0; i < k;i++)
    {
        cin >> b >> aa;
        a[b] += aa;
    }
    cin >> k;
    for (int i = 0; i < k;i++)
    {
        cin >> b >> aa;
        a[b] += aa;
    }
    for (int i = 0; i <1001;i++)
    {
        if(a[i])
            cnt++;
    }
    cout << cnt;
    for (int i =1000; i >=0;i--)
    {
        if(a[i])
            printf(" %d %.1lf", i, a[i]);
    }
    return 0;
}