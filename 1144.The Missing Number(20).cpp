#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin >> n;
    set<int>ans;
    for (int i = 0; i < n;i++)
    {
        int temp;
        scanf("%d", &temp);
        if(temp>0)
            ans.insert(temp);
    }
    int cnt = 1;
    for (auto it = ans.begin(); it != ans.end();it++)
    {
        if(*it!=cnt)
        {
            cout << cnt;
            return 0;
        }
        cnt++;
    }
    cout << cnt;
    return 0;
}