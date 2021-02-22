#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    string id;
    int score, fin_rank, local, loc_rank;
};
bool cmp(node a, node b)
{
    if(a.score!=b.score)
    return a.score > b.score;
    else
    {
        return a.id < b.id;
    }
    
}
int main()
{
    int n, k;
    cin >> n;
    vector<node> ans;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        vector<node> loc(k);
        for (int j = 0; j < k; j++)
        {
            cin >> loc[j].id >> loc[j].score;
            loc[j].local = i + 1;
        }
        sort(loc.begin(), loc.end(), cmp);
        loc[0].loc_rank = 1;
        ans.push_back(loc[0]);
        for (int j = 1; j < k; j++)
        {
            if (loc[j].score != loc[j - 1].score)
                loc[j].loc_rank = j + 1;
            else
            {
                loc[j].loc_rank = loc[j - 1].loc_rank;
            }
            ans.push_back(loc[j]);
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    ans[0].fin_rank = 1;
    for (int j = 1; j < ans.size(); j++)
    {
        if (ans[j].score != ans[j - 1].score)
            ans[j].fin_rank = j + 1;
        else
        {
            ans[j].fin_rank = ans[j - 1].fin_rank;
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size();i++)
    {
        cout << ans[i].id << " " << ans[i].fin_rank << " " << ans[i].local << " " << ans[i].loc_rank << endl;
    }
        return 0;
}