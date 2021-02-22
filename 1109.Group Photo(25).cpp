#include<bits/stdc++.h>
using namespace std;
/*
简单模拟 坑点是数组越界了 
模拟每一排的时候要用while
不能用for i<n/k
*/
struct person
{
    string name;
    int height;
};
bool cmp(person a,person b)
{
    if (a.height!=b.height)
    {
        return a.height > b.height;   
    }
    else
        return a.name < b.name;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<person> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].name >> v[i].height;
    }
    sort(v.begin(),v.end(), cmp);
    int cnt = 0,row=k;
    while (row--)
    {
        int t = row == k ? n / k + n % k : n / k;
        // cout << row << endl;
        vector<person> temp(t);
        int p = t/2-1, q = t/2;//左右指针
        int flag = 1;
        while (t--)
        {
            if(flag)
            {
                temp[q++] = v[cnt++];
                flag = 0;
            }
            else
            {
                flag = 1;
                temp[p--] = v[cnt++];
            }
        }
        for (int j = 0; j < temp.size();j++)
        {
            cout << temp[j].name;
            if (j!=temp.size()-1)
            {
                printf(" ");
            }
            else
                printf("\n");
        }
        row--;
    }
    return 0;
}