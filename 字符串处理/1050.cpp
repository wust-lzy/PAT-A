#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
字符串减法
*/
int main()
{
    map<char,bool> book;
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for (int i = 0; i < s2.size();i++)
    {
        book[s2[i]] = 1;
    }
    for (int i = 0; i < s1.size();i++)
    {
        if(!book[s1[i]])
            cout << s1[i];
    }
        return 0;
}