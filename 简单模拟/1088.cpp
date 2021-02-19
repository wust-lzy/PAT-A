#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
分数的四则运算  太麻烦了
讨论分子分母为负数和0的情况
*/
struct fraction
{
    ll fz, fm;
    fraction(){}
    fraction(ll a,ll b):fz(a),fm(b){}
};
ll gcd(ll a,ll b)
{
    return a % b == 0 ? b : gcd(b, a % b);
}
void func(fraction a)
{
    if (a.fz*a.fm==0)
    {
        if (a.fm==0)
        {
            printf("Inf");
        }
        else
        {
            printf("0");
        }
        return;
    }
    if (a.fz%a.fm==0)
    {
        a.fz /= a.fm;
        if (a.fz<0) //异号的情况
        {
            printf("(%lld)",a.fz);
        }
        else
        {
            printf("%lld", a.fz);
        }
    }
    else
    {
        ll g = abs(gcd(a.fz, a.fm));
        a.fz /= g;
        a.fm /= g;
        ll ans = abs(a.fz / a.fm);
        a.fz %= a.fm;
        if (a.fz<0||a.fm<0) //异号的情况  不能用*  防止溢出
        {
            if (ans)
            {
                printf("(-%lld %lld/%lld)",ans,abs(a.fz),abs(a.fm));
            }
            else
                printf("(-%lld/%lld)",abs(a.fz),abs(a.fm));
        }
        else
        {
            if (ans)
            {
                printf("%lld %lld/%lld",ans,a.fz,a.fm);
            }
            else
                printf("%lld/%lld", a.fz,a.fm);
        }
    }  
}
int main()
{
    fraction a, b;
    scanf("%lld/%lld %lld/%lld", &a.fz, &a.fm, &b.fz, &b.fm);
    func(a); //加法
    cout << " + ";
    func(b);
    cout << " = ";
    func(fraction((a.fz * b.fm + b.fz * a.fm), (a.fm * b.fm)));
    cout << endl;

    func(a); //减法
    cout << " - ";
    func(b);
    cout << " = ";
    func(fraction((a.fz * b.fm - b.fz * a.fm), (a.fm * b.fm)));
    cout << endl;

    func(a); //乘法
    cout << " * ";
    func(b);
    cout << " = ";
    func(fraction((a.fz * b.fz), (a.fm * b.fm)));
    cout << endl;

    func(a); //除法
    cout << " / ";
    func(b);
    cout << " = ";
    func(fraction((a.fz * b.fm), (a.fm * b.fz)));
    return 0;
}
/*
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)

2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)

1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf

1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
*/