#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
简单结构体排序题
结构体构造函数  带形参的要加上默认的参数
*/
struct Stu
{
    string name, id;
    int grade;
    Stu(){}
    Stu(string a,string b,int c):name(a),id(b),grade(c){}
};
bool cmp(Stu a,Stu b)
{
    return a.grade > b.grade;
}
int main()
{
    int n, low, high;
    cin >> n;
    vector<Stu> book(n), ans;
    for (int i = 0; i < n; i++)
    {
        cin >> book[i].name >> book[i].id >> book[i].grade;
    }
    cin >> low >> high;
    for (int i = 0; i < n; i++)
    {
        if (book[i].grade>=low&&book[i].grade<=high)
        {
            // Stu temp = {book[i].name, book[i].id, book[i].grade};
            ans.push_back(Stu(book[i].name, book[i].id, book[i].grade));
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    if (!ans.empty())
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i].name << " " << ans[i].id << "\n";
        }
    }
    else
    {
        cout << "NONE";
    }
    return 0;
}
