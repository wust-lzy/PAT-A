#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isprime(int n)
{
    if(n<=1)
        return 0;
    for (int i = 2; i*i <=n; i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}
int main()
{
    int n,k;
    cin >> n;
    int q[n];
    unordered_map<int, int> m;
    bool check[10000]={0};
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        m[t] = i + 1;
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int t;
        scanf("%d", &t);
        if (!m[t])
        {
            printf("%04d: Are you kidding?\n", t);
        }
        else if(check[t])
        {
            printf("%04d: Checked\n", t);
        }
        
        else if (m[t]==1)
        {
            printf("%04d: Mystery Award\n", t);
        }
        else if (isprime(m[t]))
        {
            printf("%04d: Minion\n", t);
        }
        else
        {
            printf("%04d: Chocolate\n", t);
        }
        check[t] = 1;
    }
    return 0;
}