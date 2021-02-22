#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
素数打表,n为long int  根号n不超过50000
遍历质数表，一直除
*/
int main()
{
    vector<int> prime(50000, 1);
    long int n;
    cin >> n;
    cout << n << "=";
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    for (int i = 2; i * i < 50000; i++)
    {
        for (int j = 2; j * i < 50000; j++)
        {
            prime[j * i] = 0;
        }
    }
    int first = 0;
    for (int i = 2; i < 50000 && n >= 2; i++)
    {
        int cnt = 0, flag = 0;
        while (prime[i] && n % i == 0)
        {
            flag = 1;
            cnt++;
            n /= i;
        }
        if (!flag)
            continue;
        if (!first)
            first = 1;
        else
        {
            printf("*");
        }
        printf("%d", i);
        if (cnt >= 2)
            printf("^%d", cnt);
    }
    return 0;
}