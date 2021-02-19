#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
简单模拟题  有个坑就是要补0到4位数
*/
int func(int n)
{
    while (n<1000)  //补0 到4位
    {
        n *= 10;
    }
    vector<int> num;
    while (n)
    {
        num.push_back(n % 10);
        n /= 10;
    }
    sort(num.begin(),num.end());
    //7766 - 6677 = 1089
    int maxn=num[3] * 1000 + num[2] * 100 + num[1] * 10 + num[0];
    int minn=num[0] * 1000 + num[1] * 100 + num[2] * 10 + num[3];
    printf("%04d - %04d = %04d\n", maxn, minn, maxn - minn);
    return maxn - minn;
}
int main()
{
    int n;
    cin >> n;
    while(n!=0)
    {
        n = func(n);
        if (n==6174)
        {
            break;
        }
    }
    return 0;
}