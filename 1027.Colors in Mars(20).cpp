#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char num[14] = {"0123456789ABC"};
int main()
{
    int a,fir=1;
    for (int i = 0; i < 3;i++)
    {
        cin >> a;
        if(fir)
        {
            cout << "#";
            fir = 0;
        }
        cout << num[a / 13] << num[a % 13];
    }
        return 0;
}