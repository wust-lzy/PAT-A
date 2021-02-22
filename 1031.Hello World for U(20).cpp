#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    char ans[100][100];
    fill(ans[0], ans[0] + 100 * 100, '*');
    string s;
    cin >> s;
    int len = s.length();
    int n, n2 = 3,cnt=0;
    bool flag = 1;
    while (flag)
    {
        n = (len + 2 - n2) / 2;
        if (n2 >= n && (2 * n + n2 - 2) == len)
            flag = 0;
        else
        {
            n2++;
        }
    }
    // cout << n << " " << n2 << " " << len + 2 - n - n2 << endl;
    for (int j = 0; j < n; j++)
        ans[j][0] = s[cnt++];
    for (int i = 1; i < n2; i++)
        ans[n - 1][i] = s[cnt++];
    for (int i = n - 2; i >= 0; i--)
        ans[i][n2 - 1] = s[cnt++];
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < n2;j++)
        {
            if(ans[i][j]!='*')
                cout << ans[i][j];
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
        return 0;
}