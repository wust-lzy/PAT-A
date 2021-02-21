#include <iostream>
#include<unordered_set>
#include<vector>
using namespace std;
int main()
{
    int n, m, k;
    cin >> n >> m;
    vector<pair<int,int > >p;
    for (int i = 0; i < m;i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        p.push_back(pair<int,int>(a,b));
    }
    cin >> k;
    for (int i = 0; i < k;i++)
    {
        int flag = 1;
        unordered_set<int> s;
        vector<int> colors(n);
        for (int j = 0; j < n;j++)
        {
            scanf("%d", &colors[j]);
            s.insert(colors[j]);
        }
        for (int j = 0; j < m;j++)//上色
        {
            if(colors[p[j].first]==colors[p[j].second])
            {
                flag = 0;
                printf("No\n");
                break;
            }
        }
        if(flag)
            printf("%d-coloring\n", s.size());
    }
        return 0;
}