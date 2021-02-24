#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
超级难的模拟题
分析：1.用数组arr标记两个人是否是朋友（邻接矩阵表示），用v标记所有人的同性朋友（邻接表表示）
2.对于一对想要在一起的A和B，他们需要先找A的所有同性朋友C，再找B的所有同性朋友D，
当C和D两人是朋友的时候则可以输出C和D
3.A在寻找同性朋友时，需要避免找到他想要的伴侣B，所以当当前朋友就是B或者B的同性朋友就是A时舍弃该结果
4.输出时候要以4位数的方式输出，所以要%04d
5.如果用int接收一对朋友，-0000和0000对于int来说都是0，将无法得知这个人的性别，
也就会影响他找他的同性朋友的那个步骤，所以考虑用字符串接收，
因为题目中已经表示会以符号位加四位的方式给出输入，所以只要判断字符串是否长度相等，
如果长度相等说明这两个人是同性
6.结果数组因为必须按照第一个人的编号从小到大排序（当第一个相等时按照第二个人编号的从小到大排序），
所以要用sort对ans数组排序后再输出结果
*/
unordered_map<int, int> arr; //用一个map记录二维数组的信息 *10000的方式实现
struct node
{
    int a, b;
};
bool cmp(node x,node y)
{
    return x.a != y.a ? x.a < y.a : x.b < y.b;
}
int main()
{
    int n, m, k;
    scanf("%d %d", &n, &m);
    vector<int> v[10000];
    for (int i = 0; i < m;i++)
    {
        string a, b;
        cin >> a >> b;
        if(a.length()==b.length())
        {
            v[abs(stoi(b))].push_back(abs(stoi(a)));
            v[abs(stoi(a))].push_back(abs(stoi(b)));
        }
        arr[abs(stoi(a)) * 10000 + abs(stoi(b))] = 1;
        arr[abs(stoi(b)) * 10000 + abs(stoi(a))] = 1;
    }
    scanf("%d", &k);
    for (int i = 0; i < k;i++)
    {
        int c, d;
        scanf("%d %d", &c, &d);
        vector<node> ans;
        for (int j = 0; j < v[abs(c)].size();j++)
        {
            for (int k = 0; k < v[abs(d)].size();k++)
            {
                if(v[abs(c)][j]==abs(d)||v[abs(d)][k]==abs(c))
                    continue;
                if(arr[v[abs(c)][j]*10000+v[abs(d)][k]])
                    ans.push_back(node{v[abs(c)][j], v[abs(d)][k]});
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        printf("%d\n", ans.size());
        for (int j = 0; j < ans.size();j++)
            printf("%04d %04d\n", ans[j].a, ans[j].b);
    }
    return 0;
}
