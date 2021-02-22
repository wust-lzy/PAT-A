#include <bits/stdc++.h>
using namespace std;
int msize, n, m;
unordered_map<int, int> vis;
bool isprime(int x)
{
    if (x < 2)
        return 0;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;
    return 1;
}
int Quadratic(int index)
{
    int ans;
    for (int i = 0; i < msize;i++)
    {
        ans = (index + i * i) % msize;
        if(!vis[ans])
        {
            vis[ans] = 1;
            return ans;
        }
    }
    return -1;
}
int main()
{
    int temp;
    cin >> msize >> n >> m;
    while(!isprime(msize))
        msize++;
    vector<int> v(msize);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        int index = Quadratic(temp);
        if(index!=-1)
            v[index] = temp;
        else
            printf("%d cannot be inserted.\n",temp);
    }
    int total = 0;
    for (int i = 0; i < m;i++)
    {
        scanf("%d", &temp);
        for (int j = 0; j <=msize;j++)
        {
            total++;
            int index = (temp + j * j) % msize;
            if(v[index]==temp||v[index]==0)
                break;
        }
    }
    // cout << total << " " << m << endl;
    printf("%.1lf\n", total*1.0 / m);
    return 0;
}