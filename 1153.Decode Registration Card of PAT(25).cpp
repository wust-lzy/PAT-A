#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    string id;
    int score;
};
bool cmp(node a, node b)
{
    if (a.score != b.score)
        return a.score > b.score;
    else
        return a.id < b.id;
}
bool cmp2(pair<string, int> a, pair<string, int> b)
{
    if (a.second != b.second)
        return a.second > b.second;
    else
        return a.first < b.first;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<node> ans[3], v(n); //A,B,T
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].id >> v[i].score;
        char c = v[i].id[0];
        if (c == 'A')
            ans[0].push_back(v[i]);
        else if (c == 'B')
            ans[1].push_back(v[i]);
        else
            ans[2].push_back(v[i]);
    }
    for (int i = 0; i < 3; i++)
        sort(ans[i].begin(), ans[i].end(), cmp);
    for (int i = 0; i < m; i++)
    {
        int type;
        string term;
        cin >> type >> term;
        printf("Case %d: %d %s\n", i + 1, type, term.c_str());
        if (type == 1)
        {
            int index;
            if (term == "A")
                index = 0;
            else if (term == "B")
                index = 1;
            else
                index = 2;
            if (ans[index].empty())
                printf("NA\n");
            else
                for (int j = 0; j < ans[index].size(); j++)
                    printf("%s %d\n", ans[index][j].id.c_str(), ans[index][j].score);
        }
        else if (type == 2)
        {
            int cnt = 0, total = 0;
            for (int j = 0; j < n; j++)
            {
                if (v[j].id.substr(1, 3) == term)
                {
                    cnt++;
                    total += v[j].score;
                }
            }
            if(cnt==0)
                printf("NA\n");
            else
                printf("%d %d\n", cnt, total);
        }
        else
        {
            vector<pair<string, int> > ans;
            unordered_map<string, int> cnt;
            for (int j = 0; j < n; j++)
            {
                if (v[j].id.substr(4, 6) == term)
                    cnt[v[j].id.substr(1, 3)]++;
            }
            for (auto it : cnt)
                ans.push_back(pair<string, int>(it.first, it.second));
            if(ans.empty())
                printf("NA\n");
            else
            {
                sort(ans.begin(), ans.end(), cmp2);
                for (auto it : ans)
                    printf("%s %d\n", it.first.c_str(), it.second);
            }
        }
    }
    return 0;
}