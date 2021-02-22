#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
简单模拟   读题很困难
*/
bool cmp(int a,int b)
{
    return a > b;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end(),cmp);
    int i = 0;
    while (v[i]>i+1)
    {
        i++;
    }
    cout << i;
    return 0;
}