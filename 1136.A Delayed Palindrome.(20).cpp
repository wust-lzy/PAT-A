#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string add(string a,string b)
{
    string ans;
    int na[1005]={0}, nb[1005]={0};
    int la = a.size(), lb = b.size();
    for (int i = 0; i < la;i++)
        na[la - 1 - i] = a[i] - '0';
    for (int i = 0; i < lb;i++)
        nb[lb - 1 - i] = b[i] - '0';
    int lmax = la > lb ? la : lb;
    for (int i = 0; i < lmax;i++)
        na[i] += nb[i], na[i + 1] += na[i] / 10, na[i] %= 10;
    if(na[lmax])
        lmax++;
    for (int i = lmax - 1; i >= 0;i--)
        ans += na[i] + '0';
    return ans;
}
bool check(string s)
{
    string temp = s;
    reverse(temp.begin(), temp.end());
    return s == temp;
}
int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < 10; i++)
    {
        if (check(s))
        {
            //255552 is a palindromic number.
            cout << s << " is a palindromic number.\n";
            return 0;
        }
        string temp = s;
        //97152 + 25179 = 122331
        reverse(temp.begin(), temp.end());
        cout << s << " + " << temp << " = " << add(s, temp) << endl;
        s = add(s, temp);
    }
    cout << "Not found in 10 iterations.\n";
    return 0;
}