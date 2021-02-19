#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
哈希表 记录一队情侣是不是都出现了
*/
int cp1[100000], cp2[100000];
bool ok[100000];
int main()
{
    int n,a,b;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        cp1[a] = b;
        cp2[b] = a;
    }
    int q,fir=1;
    cin >> q;
    vector<int> v(q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &v[i]);
        ok[v[i]] = 1;
    }
    vector<int> ans;
    for (int i = 0; i < q; i++)
    {
        if(ok[cp1[v[i]]]||ok[cp2[v[i]]])
            continue;
        else
        {
            ans.push_back(v[i]);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto val:ans)
    {
        if(fir)
        {
            printf("%05d",val);
            fir = 0;
        }
        else
            printf(" %05d", val);
    }
    return 0;
}