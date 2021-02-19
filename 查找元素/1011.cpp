#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    map<int, char> m;
    m[0] = 'W';
    m[1] = 'T';
    m[2] = 'L';
    double a[3][3], index1=-1, index2=-1, index3=-1;
    int i, j, ans1, ans2, ans3;
    for (int i = 0; i < 3;i++)
        for (int j = 0; j < 3;j++)
            cin >> a[i][j];
    for (int i = 0; i < 3;i++)
    {
        if(a[0][i]>index1)
        {
            index1 = a[0][i];
            ans1 = i;
        }
        if(a[1][i]>index2)
        {
            index2 = a[1][i];
            ans2 = i;
        }
        if(a[2][i]>index3)
        {
            index3 = a[2][i];
            ans3 = i;
        }
    }
    double ans = (index1 * index2 * index3 * 0.65 - 1) * 2;
    printf("%c %c %c %.2lf", m[ans1], m[ans2], m[ans3], ans);
    return 0;
}