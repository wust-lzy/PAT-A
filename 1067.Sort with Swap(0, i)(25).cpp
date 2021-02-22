#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
贪心算法
先让0归位，再判断i和a[i]是否相等，不相等就交换0和a[i]
因为在0归位的过程中，可能会让a[i]归位
如果直接让a[i]和a[0]交换 ， 就可能会出现浪费一次 交换次数
*/
int main()
{
    int a[100001], t;
    int n,cnt=0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        a[t] = i;
    }
    for (int i = 0; i < n; i++)
    {
        if(a[i]!=i)
        {
            while (a[0]!=0)
            {
                swap(a[0], a[a[0]]);
                cnt++;
            }
            if(a[i]!=i)
            {
                swap(a[i], a[0]);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}