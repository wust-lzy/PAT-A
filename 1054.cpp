#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
读懂题意，超过总面积一半的数  直接输出，然后退出
*/
int main()
{
    map<int, int> book;
    int m, n;
    cin >> m >> n;
    int half = m * n / 2;
    for (int i = 0; i < n;i++)
        for (int j = 0; j < m;j++)
        {
            int t;
            scanf("%d", &t);
            book[t]++;
            if(book[t]>half)
            {
                printf("%d\n", t);
                return 0;
            }
        }
    return 0;
}