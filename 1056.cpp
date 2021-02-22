#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
队列模拟  这题读题比较困难
每个老鼠分组之后 最肥的晋级，被淘汰的排名为groups+1
*/
struct node
{
    int weight, rank, index;
};
int main()
{
    int np, ng;
    scanf("%d%d", &np, &ng);
    vector<node> book(np);
    vector<int> order(np);
    queue<node> q;
    for (int i = 0; i < np; i++)
    {
        book[i].index = i;
        scanf("%d", &book[i].weight);
    }
    for (int i = 0; i < np; i++)
    {
        scanf("%d", &order[i]);
    }

    for (int i = 0; i < np; i++)
    {
        q.push(book[order[i]]);
    }
    while (!q.empty())
    {
        if (q.size() == 1)
        {
            node temp = q.front();
            q.pop();
            book[temp.index].rank = 1;
        }
        else
        {
            int sz = q.size();
            int groups = sz / ng; //分组
            if (sz % ng != 0)
                groups++;
            for (int i = 0; i < groups; i++)
            {
                vector<node> t;
                int maxn = -1, max_index = -1;
                int nz = i == groups - 1 ? (sz - (groups - 1) * ng) :ng ; //对前groups-1组和最后一组进行讨论
                for (int j = 0; j < nz; j++)
                {
                    node temp = q.front();
                    q.pop();
                    t.push_back(temp);
                    book[temp.index].rank = groups + 1; //被淘汰的老鼠
                    if (maxn < temp.weight)
                    {
                        max_index = j;
                        maxn = temp.weight;
                    }
                }
                q.push(t[max_index]); //将最肥的老鼠入队
                t.clear();
            }
        }
    }
    for (int i = 0; i < np; i++)
    {
        cout << book[i].rank;
        if (i != np - 1)
            printf(" ");
    }
    return 0;
}