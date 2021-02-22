#include <bits/stdc++.h>
using namespace std;
/*
判断质数+平方探测法
平方探测法探测数组下标
*/
int m, n;
map<int, bool> book;
bool isprime(int n)
{
    if (n <= 1)
        return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}
int index(int key)
{
    int ans;
    for (int step = 0; step <m; step++)
    {
        ans = (key + step * step) % m;
        if (!book[ans])
        {
            book[ans] = 1;
            return ans;
        }
    }
    return -1;
}
int main()
{
    vector<int> ans;
    cin >> m >> n;
    while (!isprime(m))
    {
        m++;
    }
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        temp %= m;
        ans.push_back(index(temp));
    }
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == -1)
        {
            printf("-");
        }
        else
        {
            printf("%d", ans[i]);
        }
        if (i != ans.size() - 1)
        {
            printf(" ");
        }
    }
    return 0;
}