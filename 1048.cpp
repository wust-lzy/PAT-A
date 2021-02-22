#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int book[1001];
/*
简单两数之和问题
*/
int main()
{
    int n,m;
    scanf("%d %d", &n, &m);
    vector<int> v(n);
    for (int i = 0; i < n;i++)
    {
        scanf("%d", &v[i]);
        book[v[i]]++;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n&&v[i]<=m/2;i++)
    {
        book[v[i]]--;
        int temp = m - v[i];
        if(book[temp]>0)
        {
            printf("%d %d\n", v[i], temp);
            return 0;
        }
        book[v[i]]++;
    }
    cout << "No Solution";
    return 0;
}