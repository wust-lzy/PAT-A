#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
和1089类似
换成了堆排序。
*/
int a[105], b[105];
void downAdjust(int low, int high)
{
    int i = low, j = i * 2;
    while (j <= high)
    {
        if (j + 1 <= high && b[j + 1] > b[j])
            j++;
        if (b[j] > b[i])
        {
            swap(b[j], b[i]);
            i = j;
            j = i * 2;
        }
        else
            break;
    }
}
int main()
{
    int n, i, j;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    for (i = 1; i <= n; i++)
        cin >> b[i];
    i = 0;
    while (i <= n - 1 && b[i] <= b[i + 1])
    {
        i++;
    }
    for (j = i + 1; a[j] == b[j] && j <= n; j++)
        ;
    if (j == n + 1)
    {
        cout << "Insertion Sort" << endl;
        sort(a + 1, a + i + 2);
        for (i = 1; i <= n; i++)
        {
            printf("%d", a[i]);
            if (i != n)
            {
                printf(" ");
            }
        }
    }
    else //堆排序
    {
        cout << "Heap Sort" << endl;
        i = n;
        while (i > 2 && b[i] >= b[1])
            i--;
        swap(b[1], b[i]);
        downAdjust(1, i - 1);
        for (i = 1; i <= n; i++)
        {
            printf("%d", b[i]);
            if (i != n)
            {
                printf(" ");
            }
        }
    }

    return 0;
}