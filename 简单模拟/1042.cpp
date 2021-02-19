#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
简单模拟
*/
int main()
{
    char book[6]="SHCDJ";
    int k, order[55], start[55], end[55];
    scanf("%d", &k);
    for (int i = 1; i <= 54;i++)
    {
        scanf("%d", &order[i]);
        end[i] = i;
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = 1; j <= 54;j++)
        {
            start[j]=end[j];
        }
        for (int j = 1; j <= 54;j++)
        {
            end[order[j]] = start[j];
        }
    }
    for (int i = 1; i <= 54;i++)
    {
        printf("%c%d", book[(end[i]-1) / 13], (end[i]-1) % 13+1);
        if(i!=54)
            printf(" ");
    }
        return 0;
}