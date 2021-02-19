#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct stu
{
    string name,sex,id;
    int grade;
    stu(string n,string s,string i,int gr):name(n),sex(s),id(i),grade(gr){}
};
bool cmp(stu a,stu b)
{
    return a.grade < b.grade;
}
int main()
{
    vector<stu> boys, girls;
    int n,grade;
    string name, sex, id;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        cin >> name >> sex >> id >> grade;
        if(sex=="M")
            boys.push_back(stu(name, sex, id, grade));
        else if(sex=="F")
            girls.push_back(stu(name, sex, id, grade));
    }
    sort(boys.begin(), boys.end(), cmp);
    sort(girls.begin(), girls.end(), cmp);
    if(!girls.size())
    {
        cout << "Absent" << endl;
        cout << boys[0].name << " " << boys[0].id << endl;
        cout << "NA";
    }
    else if(!boys.size())
    {
        cout << girls[girls.size()-1].name << " " << girls[girls.size()-1].id << endl;
        cout << "Absent" << endl;
        cout << "NA";
    }
    else
    {
        cout << girls[girls.size()-1].name << " " << girls[girls.size()-1].id << endl;
        cout << boys[0].name << " " << boys[0].id << endl;
        cout << girls[girls.size() - 1].grade - boys[0].grade << endl;
    }
    return 0;
}