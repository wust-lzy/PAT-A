#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct person
{
    int come, time;
} p[10005];
bool cmp(person p1, person p2)
{
    return p1.come < p2.come;
}
int n, k, cnt = 0, total = 0;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        int h, m, s, t;
        scanf("%d:%d:%d %d", &h, &m, &s, &t);
        int sum = h * 3600 + m * 60 + s;
        if (sum > 61200)
            continue;
        p[++cnt].time = t * 60;
        p[cnt].come = sum;
    }
    sort(p + 1, p + 1 + cnt, cmp);
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < k; i++)
        q.push(28800);
    for (int i = 1; i <= cnt; i++)
    {
        if (p[i].come < q.top()) //来早了
        {
            total += q.top() - p[i].come;
            q.push(q.top() + p[i].time);
            q.pop();
        }
        else
        {
            q.push(p[i].come + p[i].time);
            q.pop();
        }
    }
    if (!cnt)
        cout << "0.0";
    else
    {
        printf("%.1lf", (double)total / (60.0 * cnt));
    }

    return 0;
}