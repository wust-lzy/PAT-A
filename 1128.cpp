#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
判断坐标条件。
*/
bool check(pair<int,int> a,pair<int,int> b)
{
    if(a.first==b.first||a.second==b.second)
        return 0;
    else if (abs(a.first-b.first)==abs(a.second-b.second))
        return 0;
    return 1;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int k,t;
        scanf("%d", &k);
        vector<pair<int, int> >v(k);
        for (int i = 0; i < k; i++)
        {
            scanf("%d", &t);
            v[i] = pair<int, int>(t, i + 1);
        }
        int flag = 1;
        for (int i = 0; i < k&&flag; i++)
        {
            for (int j = i + 1; j < k;j++)
            {
                // cout << v[i].first << " " << v[i].second << "---" << v[j].first << " " << v[j].second << "---" << check(v[i], v[j]) << endl;
                if(!check(v[i],v[j]))
                {
                    flag = 0;
                    break;
                }
            }
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}