#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
水题
*/
int main()
{
    map<int, int> book;
    int n, a;
    bool flag = 0;
    cin >> n;
    vector<int> ans;
    for (int i = 0; i < n;i++)
    {
        scanf("%d", &a);
        ans.push_back(a);
        book[a]++;
    }
    for (int i = 0; i < n;i++)
    {
        if(book[ans[i]]==1)
        {
            flag = 1;
            printf("%d", ans[i]);
            break;
        }
    }
    if(!flag)
        printf("None\n");
    return 0;
}