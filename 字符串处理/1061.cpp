#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
阅读理解题，第一个条件是找到相同的大写字母
第二个条件是相同的数字或者相同的A~N的字母
第三个条件找到相同的英文字母
*/
int main()
{
    string book[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    int index = -1, h, s;
    string ans1;
    for (int i = 0; i < a.size() && i < b.size();i++)
    {
        if(a[i]==b[i]&&a[i]>='A'&&a[i]<='G')
        {
            ans1 = book[a[i] - 'A'];
            index = i;
            break;
        }
    }
    for (int i = index+1; i < a.size() && i < b.size();i++)
    {
        if(a[i]==b[i]&&(isdigit(a[i])||a[i]>='A'&&a[i]<='N'))
        {
            if(isupper(a[i]))
            {
                h = 10 + (a[i] - 'A');
            }
            else
            {
                h = a[i] - '0';
            }
            break;
        }
    }
    for (int i = 0; i < c.size() && i < d.size();i++)
    {
        if(c[i]==d[i]&&isalpha(c[i]))
        {
            s = i;
            break;
        }
    }
    cout << ans1 << " ";
    printf("%02d:%02d", h, s);
    return 0;
}