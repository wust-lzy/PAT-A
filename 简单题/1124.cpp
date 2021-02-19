#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
简单题  但是花了好长时间。。。
*/
int main()
{
    int m, n, s;
    cin >> m >> n >> s;
    string book[m+1];
    unordered_map<string, int> ok;
    for (int i = 1; i <= m; i++)
        cin >> book[i];
    int flag = 0, i = s;
    while (1)
    {
        if (i > m)
            break;
        if (!ok[book[i]])
        {
            cout << book[i] << endl;
            ok[book[i]] = 1;
            flag = 1;
        }
        else
        {
            while (ok[book[i]]&&i<m)
                i++;
            if (ok[book[i]])
                break;
            cout << book[i] << endl;
        }
        i += n;
    }
    if (!flag)
        cout << "Keep going...";
    return 0;
}