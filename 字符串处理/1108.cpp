#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
从字符串中提取保留2位小数的浮点数
用到了sscanf函数和sprintf函数
*/
int main()
{
    int n,cnt=0;
    char a[50], check[50];
    double temp,sum=0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int flag = 1;
        scanf("%s", a);
        sscanf(a, "%lf", &temp);  //按照%lf格式从a中写入到temp中
        sprintf(check, "%.2lf", temp);  //按照%.2lf写出到check数组
        for (int j = 0; j < strlen(a); j++)
        {
            if (a[j]!=check[j])
            {
                
                flag = 0;
                break;
            }
        }
        if(!flag||temp>1000||temp<-1000)
        {
            printf("ERROR: %s is not a legal number\n", a);
            continue;
        }
        cnt++;
        sum += temp;
    }
    if(!cnt)
    {
        printf("The average of 0 numbers is Undefined");
    }
    else
    {
        if (cnt==1)
        {
            printf("The average of 1 number is %.2lf", sum);
        }
        else
            printf("The average of %d numbers is %.2lf", cnt, sum / cnt);
    }
    return 0;
}