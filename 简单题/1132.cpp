#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        string z;
        cin >> z;
        int len = z.length();
        int a = stoi(z.substr(0, len / 2));
        int b = stoi(z.substr(len / 2, len / 2));
        if(b==0)
        {
            cout << "No\n";
            continue;
        }
        if(stoi(z)%(a*b)==0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}