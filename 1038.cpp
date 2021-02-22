#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(string a,string b)
{
    return a + b < b + a;
}
int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    string ans;
    for (int i = 0; i < n;i++)
        cin >> v[i];
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n;i++)
        ans+= v[i];
    while(ans[0]=='0')
        ans.erase(ans.begin());
    if(ans.length()==0)
        cout << 0;
    else
    cout << ans;
    return 0;
}