#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(string &s)
{
    for (int i = 0; i < s.size();i++)
    {
        if(s[i]=='1'||s[i]=='0'||s[i]=='l'||s[i]=='O')
            return 1;
    }
    return 0;
}
void work(string &s)
{
    for (int i = 0; i < s.size();i++)
    {
        if(s[i]=='1')
            s[i] = '@';
        else if(s[i]=='0')
            s[i] = '%';
        else if(s[i]=='l')
            s[i] = 'L';
        else if(s[i]=='O')
            s[i] = 'o';
    }
}
int main()
{
    int n,cnt=0;
    vector< pair<string, string> > ans;
    string a, b;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        cin >> a >> b;
        if(check(b))
        {
            work(b);
            cnt++;
            ans.push_back(make_pair(a, b));
        }
    }
    if(!cnt)
    {
        if(n==1)
        printf("There is %d account and no account is modified", n);
        else
        {
            printf("There are %d accounts and no account is modified", n);
        }
        
    }
    else
    {
        printf("%d\n", cnt);
        for (int i = 0; i < ans.size();i++)
        {
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    }
    
        return 0;
}