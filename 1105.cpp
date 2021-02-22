#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
蛇形填数
*/
int main()
{
    int n;
    cin >> n;
    vector<int>v(n) ;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    int x = sqrt(n),y;
    while (n%x)
    {
        x--;
    }
    x = n / x > x ? n / x : x;
    y = n / x;
    // cout << x << " " << y;
    int book[x][y], cnt = n,a=0,b=0;
    memset(book, 0, sizeof(book));
    book[a][b] = v[--cnt];
    while (cnt>0)
    {
        while (b+1<y&&!book[a][b+1]) //右
        {
            book[a][++b] = v[--cnt];
        }
        while (a+1<x&&!book[a+1][b]) //下
        {
            book[++a][b] = v[--cnt];
        }
        while (b-1>=0&&!book[a][b-1]) //左
        {
            book[a][--b] = v[--cnt];
        }
        while (a-1>=0&&!book[a-1][b]) //上
        {
            book[--a][b] = v[--cnt];
        }
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%d", book[i][j]);
            if (j!=y-1)
            {
                printf(" ");
            }
            
        }
        printf("\n");
        }
    
    return 0;
}