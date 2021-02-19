#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n,maxn=-1;
    cin >> n;
    vector<int> v(n),ans;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    vector<int> temp(v);
    sort(temp.begin(), temp.end());
    for (int i = 0; i < n; i++)
    {
        if (v[i]==temp[i]&&temp[i]>maxn)
        {
            ans.push_back(temp[i]);
        }
        maxn = max(maxn, v[i]);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        printf("%d", ans[i]);
        if (i!=ans.size()-1)
        {
            printf(" ");
        }  
    }
    cout << endl;
    return 0;
}