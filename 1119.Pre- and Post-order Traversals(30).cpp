#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
二叉树前序和后序转中序
*/
vector<int> in, pre, post;
bool u = true;
void getin(int preleft, int preright, int postleft, int postright)
{
    if (preleft == preright)
    {
        in.push_back(pre[preleft]);
        return;
    }
    if (pre[preleft] == post[postright])
    {
        int i = preleft + 1;
        while (i <= preright && pre[i] != post[postright - 1])
            i++;
        if (i - preleft > 1)
            getin(preleft + 1, i - 1, postleft, postleft + (i - preleft - 1) - 1);
        else
            u = false;
        in.push_back(post[postright]);
        getin(i, preright, postleft + (i - preleft - 1), postright - 1);
    }
}
int main()
{
    int n;
    cin >> n;
    pre.resize(n);
    post.resize(n);
    for (int i = 0; i < n; i++)
        cin >> pre[i];
    for (int i = 0; i < n; i++)
        cin >> post[i];
    getin(0, n - 1, 0, n - 1);
    printf("%s\n", u == true ? "Yes" : "No");
    for (int i = 0; i < in.size(); i++)
    {
        cout << in[i];
        if (i != in.size() - 1)
            cout << " ";
        else
            cout << endl;
    }
    return 0;
}