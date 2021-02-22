#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
disjoint sets不相交的集合是个坑点
其实两个集合的元素相交了
*/
int main()
{
    int n;
    ll sum = 0,halfsum=0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
        sum += v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n/2;i++)
        halfsum += v[i];
    cout << n % 2 << " " << sum - 2*halfsum;
    return 0;
}