#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
水题  按位做加法，按要求进位
*/
int main()
{
    int a1, a2, a3, b1, b2, b3;
    scanf("%d.%d.%d %d.%d.%d", &a1, &a2, &a3, &b1, &b2, &b3);
    a3 += b3;
    if(a3>=29)
    {
        a3 -= 29;
        a2++;
    }
    a2 += b2;
    if (a2>=17)
    {
        a2 -= 17;
        a1++;
    }
    a1 += b1;
    printf("%d.%d.%d", a1, a2, a3);
    return 0;
}