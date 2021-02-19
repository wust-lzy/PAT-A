#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int func(int n)
{
    int sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int main()
{
    set<int> s;
    int n,t;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        s.insert(func(t));
    }
    cout << s.size()<<endl;
    int fir = 1;
    for (auto it:s)
    {
        if (fir)
        {
            printf("%d", it);
            fir = 0;
        }
        else
        {
            printf(" %d", it);
        }
    }
    return 0;
}