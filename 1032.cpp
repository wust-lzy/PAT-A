#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    char data;
    int next;
    bool flag;
}book[100000];

int main()
{
    int s1, s2, n;
    cin >> s1 >> s2 >> n;
    int a, b;
    char c;
    for (int i = 0; i < n;i++)
    {
        scanf("%d %c %d", &a, &c, &b);
        book[a] = {c, b, false};
    }
    for (int i = s1; i != -1; i = book[i].next)
    {
        book[i].flag = 1;
    }
    for (int i = s2; i != -1; i = book[i].next)
    {
        if(book[i].flag)
        {
            printf("%05d", i);
            return 0;
        }
    }
    cout << "-1";
    return 0;
}
