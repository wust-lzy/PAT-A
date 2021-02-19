#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<string, set<string> > title, author, key, pub, year;
void query(map<string,set<string> > &m,string &str)
{
    if(m.find(str)!=m.end())
    {
        for (auto it = m[str].begin(); it != m[str].end();it++)
            cout << *it << endl;
    }
    else
    {
        printf("Not Found\n");
    }
}
int main()
{
    int n,m;
    string id,a,b,c,d,e;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        cin >> id;
        cin.ignore();
        getline(cin, a);
        title[a].insert(id);
        getline(cin, b);
        author[b].insert(id);
        while(cin>>c)
        {
            key[c].insert(id);
            char cc = getchar();
            if(cc=='\n')
                break;
        }
        getline(cin, d);
        pub[d].insert(id);
        getline(cin, e);
        year[e].insert(id);
    }
    cin >> m;
    for (int i = 0; i < m;i++)
    {
        int num;
        string q;
        scanf("%d: ", &num);
        getline(cin, q);
        cout << num << ": " << q << endl;
        if(num == 1) query(title, q);
        else if(num == 2) query(author, q);
        else if(num == 3) query(key, q);
        else if(num == 4) query(pub,q);
        else if(num ==5) query(year, q);
    }
        return 0;
}